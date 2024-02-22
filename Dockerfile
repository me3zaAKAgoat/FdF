FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

# Update apt and install necessary packages in one step
RUN apt-get update && \
    apt-get install -y \
        gcc \
        make \
        xorg \
        libxext-dev \
        libbsd-dev \
        zlib1g-dev

# Copy the current directory into the /app directory of the image
COPY . /app

# Set /app as the working directory
WORKDIR /app

# Compile minilibx-linux
RUN cd minilibx-linux && \
    make && \
    cp libmlx_Linux.a /usr/local/lib/ && \
    cp mlx.h /usr/local/include/

# Compile the main program
RUN make bonus

# Define the default command to run when the container starts
CMD ["./FdF_BONUS", "test_maps/42.fdf"]
