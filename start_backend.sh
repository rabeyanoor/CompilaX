#!/bin/bash
# ─────────────────────────────────────────────
#  AetherScript Backend Launcher
# ─────────────────────────────────────────────

PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
COMPILER="$PROJECT_DIR/compiler/minilang"
VENV="$PROJECT_DIR/venv"

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  🚀 AetherScript Backend Launcher"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# 1) Check compiler binary
if [ ! -f "$COMPILER" ]; then
    echo "  ⚠️  Compiler not found! Building now..."
    cd "$PROJECT_DIR/compiler" && make
    if [ $? -ne 0 ]; then
        echo "  ❌ Build failed. Check Flex/Bison installation."
        exit 1
    fi
    echo "  ✅ Compiler built successfully."
fi
echo "  ✅ Compiler : $COMPILER"

# 2) Check venv
if [ ! -d "$VENV" ]; then
    echo "  ⚠️  Virtual environment not found! Creating..."
    python3 -m venv "$VENV"
fi

# 3) Activate venv & install deps
source "$VENV/bin/activate"
pip install -q fastapi uvicorn pydantic
echo "  ✅ Python packages ready."

# 4) Kill any old backend on port 8000
OLD_PID=$(lsof -ti:8000 2>/dev/null)
if [ -n "$OLD_PID" ]; then
    echo "  🔄 Stopping old server (PID $OLD_PID)..."
    kill "$OLD_PID" 2>/dev/null
    sleep 1
fi

# 5) Start backend
echo "  🌐 Starting server on http://localhost:8000 ..."
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cd "$PROJECT_DIR"
python backend/main.py
