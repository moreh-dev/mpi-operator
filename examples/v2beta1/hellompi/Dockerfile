# docker build -t harbor.moreh.dev/platform/mpitest:0612 . && docker push harbor.moreh.dev/platform/mpitest:0612

FROM ghcr.io/moreh-dev/base-ubuntu-rocm:20.04-5.3.3

RUN apt-get update -y && apt-get install -y openssh-server && mkdir -p /run/sshd

WORKDIR /app

COPY hello.cpp /app/hello.cpp
RUN mpic++ /app/hello.cpp -o /app/hello

