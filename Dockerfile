# Dockerfile for Data Structure Visualizer
FROM ubuntu:22.04

# Avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy project files
COPY . .

# Build the application
RUN g++ src/main.cpp src/linked_list.cpp src/data_structures.cpp -std=c++17 \
    -I./external/Crow/include \
    -I./external/asio/include \
    -o dsa_visualizer \
    -pthread \
    -DASIO_STANDALONE

# Expose port
EXPOSE 18080

# Run the application
CMD ["./dsa_visualizer"]

