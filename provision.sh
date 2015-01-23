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


# Let this script know not to run again
touch /var/vagrant_provision
