docker build -t my-fedora-image .
docker run -d -p 4242:22 -v $PWD/../:/data my-fedora-image
