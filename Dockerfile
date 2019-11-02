## В качестве базового образа для сборки используем gcc:latest
#FROM gcc:latest as build
#
## Скачаем все необходимые пакеты и выполним сборку GoogleTest
## Такая длинная команда обусловлена тем, что
## Docker на каждый RUN порождает отдельный слой,
## Влекущий за собой, в данном случае, ненужный оверхед
#RUN apt-get update && \
#    apt-get install -y cmake && \
#    mkdir build && \
#    cd build && \
#    env CC=gcc-9 CXX=g++-9 cmake .. && \
#    cmake --build .
#
#
#WORKDIR /app/build
#

FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y wget gnupg

RUN wget -O llvm.key https://apt.llvm.org/llvm-snapshot.gpg.key
RUN apt-key add llvm.key
RUN echo "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-7 main" >> /etc/apt/sources.list.d/clang.list

RUN apt-get update

RUN apt-get install -y \
    build-essential \
    cmake \
    ccache \
    ninja-build \
    clang-format \
    clang-tidy-8 \
    clang++-8 \
    llvm-8 \
    g++

RUN ln -s /usr/bin/clang-tidy-8 /usr/bin/clang-tidy
RUN ln -s /usr/bin/llvm-profdata-8 /usr/bin/llvm-profdata
RUN ln -s /usr/bin/llvm-cov-8 /usr/bin/llvm-cov

RUN apt-get install -y \
    git

RUN git clone https://github.com/google/re2 && cd re2 && make && make install
