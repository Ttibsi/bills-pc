#https://docs.docker.com/config/containers/multi-service_container/
FROM ubuntu:jammy

# hadolint ignore=DL3008
RUN apt-get update && apt-get upgrade -y && \
apt-get install --no-install-recommends \
cmake \
curl \
git \
g++ \
libpython3-dev \
make \
neovim \
python3 \
python3.10-dev \
tree -y \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/*

COPY . /bills-pc/
WORKDIR /bills-pc
