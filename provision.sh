#!/usr/bin/env bash

# Determine if this machine has already been provisioned
# Basically, run everything after this command once, and only once
if [ -f "/var/vagrant_provision" ]; then
  exit 0
fi

function say {
  printf "\n--------------------------------------------------------\n"
  printf "\t$1"
  printf "\n--------------------------------------------------------\n"
}

say "Installing handy packages"
  apt-get install -y curl git-core ftp unzip imagemagick vim colordiff gettext graphviz build-essential >/dev/null 2>&1

say "Changing start directory for Terminal to shared vagrant directory"
  echo 'cd /vagrant' >> ~/.bashrc

say "Adding git config info"
  git config --global user.email "you@example.com"
  git config --global user.name "Your Name"
  git config --global push.default simple
  git config --global credential.helper cache
  git config --global credential.helper 'cache --timeout=3600'
  git config --global core.autocrlf false

# Let this script know not to run again
touch /var/vagrant_provision
