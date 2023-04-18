FROM fedora:latest

# Install packages
RUN dnf update -y && \
    dnf install -y openssh-server make gcc vim flex flex-devel bison && \
    dnf clean all

# Set root password
RUN echo 'root:toor' | chpasswd
RUN ssh-keygen -A
RUN mkdir /var/run/sshd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
