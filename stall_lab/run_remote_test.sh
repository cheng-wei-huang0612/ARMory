#!/bin/bash
set -e  # 若任何指令失敗則腳本中斷

# === 1) 設定好你的遠端連線資料 ===
REMOTE_USER="pi"                 # 遠端使用者，如 pi、ubuntu 等
REMOTE_IP="100.73.73.113"        # 遠端 IP (或 hostname)
REMOTE_DIR="~/Documents/ARMory/stall_lab"  # 遠端的專案目錄 (放置 .S 檔案的地方)

# === 2) 將本地的修改 commit + push 到遠端 repo ===
echo "----- [LOCAL] Git add, commit, push -----"
git add .
git commit -m "Auto-commit on $(date)"
git push

# === 3) SSH 到遠端，拉下最新程式碼並執行編譯、測試 ===
echo "----- [REMOTE] SSH to ${REMOTE_USER}@${REMOTE_IP} -----"
ssh ${REMOTE_USER}@${REMOTE_IP} <<EOF
    echo "🔑 Connected to remote: \$(uname -a)"
    cd ${REMOTE_DIR} || { echo "No such dir: ${REMOTE_DIR}"; exit 1; }

    echo "----- [REMOTE] Git pull -----"
    git pull

    echo "----- [REMOTE] Building all test assemblies -----"
    gcc -O0 single_cycle_no_dep.S     -o single_cycle_no_dep
    gcc -O0 single_cycle_with_dep.S   -o single_cycle_with_dep
    gcc -O0 multi_cycle_no_dep.S      -o multi_cycle_no_dep
    gcc -O0 multi_cycle_with_dep.S    -o multi_cycle_with_dep

    echo "----- [REMOTE] Perf stat: single_cycle_no_dep -----"
    taskset -c 0 perf stat ./single_cycle_no_dep

    echo "----- [REMOTE] Perf stat: single_cycle_with_dep -----"
    taskset -c 0 perf stat ./single_cycle_with_dep

    echo "----- [REMOTE] Perf stat: multi_cycle_no_dep -----"
    taskset -c 0 perf stat ./multi_cycle_no_dep

    echo "----- [REMOTE] Perf stat: multi_cycle_with_dep -----"
    taskset -c 0 perf stat ./multi_cycle_with_dep

    echo "----- [REMOTE] All done. -----"
EOF

echo "✨ Done! Everything should be compiled & tested on the remote."

