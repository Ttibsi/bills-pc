FROM ubuntu:jammy

# hadolint ignore=DL3008
RUN apt-get update && apt-get upgrade -y && \
apt-get install --no-install-recommends \
cmake \
curl \
gdb \
git \
g++ \
libpython3-dev \
libsqlite3-dev \
make \
neovim \
python3 \
python3.10-dev \
sqlite3 \
tree -y \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/*

COPY . /bills-pc/
WORKDIR /bills-pc
