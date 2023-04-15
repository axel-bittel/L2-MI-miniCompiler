FROM fedora:latest

# Install lex and yacc, GCC and Make
RUN dnf -y update && \
    dnf -y install flex bison gcc make && \
    dnf clean all

# Create a directory for the volume
RUN mkdir /data

# Configure the volume to be linked to the file
VOLUME /data

# Enable SSH
RUN dnf -y install openssh-server && \
    systemctl enable sshd.service
RUN ssh-keygen -A

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]