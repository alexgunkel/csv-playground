FROM ubuntu:latest

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y cmake build-essential python3 git gdb \
    && mkdir -p /usr/src/clang \
    && cd /usr/src/clang

RUN cd /usr/src/clang && \
    git clone --depth 1 https://github.com/llvm/llvm-project.git

RUN mkdir /usr/src/clang/llvm-project/build && \
    cd /usr/src/clang/llvm-project/build && \
    cmake  -DLLVM_ENABLE_PROJECTS=clang -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../llvm \
    && make -j $(nproc) \
    && make install
