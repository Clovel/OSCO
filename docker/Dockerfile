# Source image ----------------------------------
FROM ubuntu:latest

# Docker image information ----------------------
LABEL maintainer="Clovis Durand <cd.clovel19@gmail.com>"
LABEL name="OSCO Stack image"

# Update package manager -------------------------
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get upgrade -y

# Install packages ------------------------------
RUN apt-get install -y \
git \
build-essential \
cmake \
pkg-config \
doxygen \
graphviz \
vim \
nano \
curl \
net-tools \
iproute2 \
sudo \
libncurses-dev \
python3 \
python3-pip

# Clean package managers ------------------------
RUN apt-get autoclean
RUN apt-get clean
RUN apt-get autoremove -y

# Set up binds/volumes --------------------------

# Set up the SSH agent --------------------------

# Make work directory ---------------------------
RUN mkdir -p /repository

# Set up development toolchains -----------------

# Set up environment variables ------------------

# Set up user (if not root) ---------------------

# Set up working directory ----------------------
WORKDIR /repository
