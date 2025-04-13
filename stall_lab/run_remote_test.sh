#!/bin/bash
set -e  # 遇到任何錯誤即中斷腳本

############################################
# 1) 參數設定
############################################
REMOTE_USER="pi"                  # 遠端使用者
REMOTE_IP="100.73.73.113"         # 遠端機器 IP 或 hostname
REMOTE_DIR="~/Documents/ARMory/stall_lab"  # 遠端專案目錄 (Git 同步處)

# 預設重複次數 (若無提供參數)
REPEAT=10000
if [ -n "$1" ]; then
    REPEAT=$1
fi

############################################
# 2) 在本地執行 Python 腳本，產生 .S 檔案
############################################
echo "🚀 Generating .S files with repeat=${REPEAT} ..."
python single_cycle_no_dep.py ${REPEAT}
python single_cycle_with_dep.py ${REPEAT}
python multi_cycle_no_dep.py ${REPEAT}
python multi_cycle_with_dep.py ${REPEAT}

############################################
# 3) Git add, commit, push 到遠端 Repo
############################################
echo "----- [LOCAL] Git add, commit, push -----"
git add .
git commit -m "Auto-commit on $(date)"
git push

############################################
# 4) SSH 登入遠端機器，拉取最新程式碼並進行編譯、測試
############################################
echo "----- [REMOTE] SSH to ${REMOTE_USER}@${REMOTE_IP} -----"
ssh ${REMOTE_USER}@${REMOTE_IP} <<EOF
    set -e
    echo "🔑 Connected to remote: \$(uname -a)"
    cd ${REMOTE_DIR} || { echo "No such dir: ${REMOTE_DIR}"; exit 1; }

    echo "----- [REMOTE] git pull -----"
    git pull

    echo "----- [REMOTE] Building all test assemblies -----"
    gcc -O0 single_cycle_no_dep.S   -o single_cycle_no_dep
    gcc -O0 single_cycle_with_dep.S -o single_cycle_with_dep
    gcc -O0 multi_cycle_no_dep.S    -o multi_cycle_no_dep
    gcc -O0 multi_cycle_with_dep.S  -o multi_cycle_with_dep

    echo "----- [REMOTE] Perf stat: single_cycle_no_dep -----"
    taskset -c 0 perf stat ./single_cycle_no_dep

    echo ""
    echo "----- [REMOTE] Perf stat: single_cycle_with_dep -----"
    taskset -c 0 perf stat ./single_cycle_with_dep

    echo ""
    echo "----- [REMOTE] Perf stat: multi_cycle_no_dep -----"
    taskset -c 0 perf stat ./multi_cycle_no_dep

    echo ""
    echo "----- [REMOTE] Perf stat: multi_cycle_with_dep -----"
    taskset -c 0 perf stat ./multi_cycle_with_dep

    echo "----- [REMOTE] All tests done. -----"
EOF

echo "✨ Done! Everything should be compiled & tested on the remote."

