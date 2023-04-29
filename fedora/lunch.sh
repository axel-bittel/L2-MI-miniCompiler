#!/bin/bash

# Name of the container
CONTAINER_NAME=fedora-container
ARG_RELOAD=relaod

  ssh-keygen -f "~/.ssh/known_hosts" -R "[localhost]:4242"
  # Build and start the container
  docker-compose up -d --build

  # Wait for the container to start SSH
  echo "Waiting for SSH to start..."
  sleep 5

  # Connect to the container via SSH
  ssh -p 4242 root@localhost
