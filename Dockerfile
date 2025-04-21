# inspired by https://github.com/Xeeynamo/sotn-decomp/blob/master/Dockerfile

# build container and tag it as sfiii-build:latest
#
# > docker build --tag sfiii-build:latest --build-arg USER=$USER .

# launch container and mount current directory under /sfiii
#
# > docker run --rm -it -v $(pwd):/sfiii sfiii-build /bin/bash

# make extract -j && make build -j

FROM --platform=linux/amd64 ubuntu:22.04

RUN dpkg --add-architecture i386
ADD tools/requirements-debian.txt /tools/requirements-debian.txt
RUN apt-get update && apt-get install -y $(cat /tools/requirements-debian.txt)

WORKDIR /sfiii
ARG USER
RUN adduser ${USER}
ENV VENV_PATH=/tools/.venv
RUN mkdir -p ${VENV_PATH}
RUN chown ${USER} /sfiii ${VENV_PATH}
USER ${USER}

# Install Python dependencies
ADD tools/requirements-python.txt /tools/requirements-python.txt
RUN python3 -m venv ${VENV_PATH} && \
    . ${VENV_PATH}/bin/activate && \
    pip install -r /tools/requirements-python.txt

RUN git config --global --add safe.directory /sfiii
