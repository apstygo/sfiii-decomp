# inspired by https://github.com/Xeeynamo/sotn-decomp/blob/master/Dockerfile

# build container and tag it as sfiii-build:latest
#
# > docker build --tag sfiii-build:latest --build-arg USER=$USER .

# launch container and mount current directory under /sfiii
#
# > docker run --rm -it -v $(pwd):/sfiii sfiii-build

# make extract -j && make build -j

FROM --platform=linux/amd64 ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
RUN dpkg --add-architecture i386
ADD tools/requirements-debian.txt /tools/requirements-debian.txt
RUN apt-get update && apt-get install -y $(cat /tools/requirements-debian.txt)

# Install Swift 6.1 dependencies
# RUN ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime && echo "Etc/UTC" > /etc/timezone
# RUN apt-get -y install gnupg2 libcurl4-openssl-dev libxml2-dev libz3-dev pkg-config python3-lldb-13 tzdata

# Zsh
RUN locale-gen en_US.UTF-8

# Cleanup
RUN apt clean

WORKDIR /sfiii
ARG USER
RUN useradd -m -s /bin/zsh ${USER}
ENV VENV_PATH=/tools/.venv
RUN mkdir -p ${VENV_PATH}
RUN chown ${USER} /sfiii ${VENV_PATH}
USER ${USER}
ENV HOME=/home/${USER}

# Install Swift
# RUN curl -O https://download.swift.org/swiftly/linux/swiftly-1.0.0-$(uname -m).tar.gz
# RUN tar -zxf swiftly-1.0.0-$(uname -m).tar.gz
# RUN ./swiftly init --skip-install
# RUN echo ". $HOME/.local/share/swiftly/env.sh" >> $HOME/.zshrc
# RUN ${HOME}/.local/share/swiftly/bin/swiftly install 6.1 --use

# Install Oh My Zsh
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended

# Install Python dependencies
ADD tools/requirements-python.txt /tools/requirements-python.txt
RUN python3 -m venv ${VENV_PATH} && \
    . ${VENV_PATH}/bin/activate && \
    pip install -r /tools/requirements-python.txt

RUN echo "source /tools/.venv/bin/activate" >> $HOME/.zshrc

RUN git config --global --add safe.directory /sfiii

# Set Zsh as default shell
SHELL ["/bin/zsh", "-c"]

CMD ["zsh"]
