#!/bin/bash

# Name of the container
CONTAINER_NAME=fedora-container
ARG_RELOAD=relaod

if `docker ps | awk -v container_name=$CONTAINER_NAME 'NR>1 && $NF != container_name { found=1 } END { print found }'`; then # Check if the container is running
  # Connect to the container via SSH
  ssh -p 4242 root@localhost
else
  ssh-keygen -f "~/.ssh/known_hosts" -R "[localhost]:4242"
  # Build and start the container
  docker-compose up -d --build

  # Wait for the container to start SSH
  echo "Waiting for SSH to start..."
  sleep 5

  # Connect to the container via SSH
  ssh -p 4242 root@localhost
fi
