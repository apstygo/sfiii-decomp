# Builde guide

## Cloning

```bash
git clone --recurse-submodules https://github.com/crowded-street/3s-decomp
```

## Setting up the environment

### Linux

1. Enable i386 architecture support and install packages.

    ```bash
    sudo dpkg --add-architecture i386
    sudo apt-get update
    sudo apt-get install -y $(cat tools/requirements-debian.txt)
    ```

2. Install Python dependencies.

    ```bash
    python3 -m venv .venv
    source .venv/bin/activate
    pip install -r tools/requirements-python.txt
    ```

3. Download build tools.

    ```bash
    make setup_tools
    ```

### macOS

1. Use the provided Dockerfile.

    ```bash
    docker build --tag sfiii-build:latest --build-arg USER=$USER .
    docker run --rm -it -v $(pwd):/sfiii sfiii-build /bin/bash
    ```

2. Activate Python venv.

    ```bash
    source /tools/.venv/bin/activate
    ```

3. Download build tools.

    ```bash
    make setup_tools
    ```

## Building

1. Put `THIRD_U.BIN` from your copy of the game in the root folder.

2. Run `splat`.

    ```bash
    make split
    ```

3. Build.

    ```bash
    make build -j
    ```

If everything's okay you'll see the message `Files match ✅`.
