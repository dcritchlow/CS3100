Vagrant.configure(2) do |config|

  config.vm.box = "ubuntu/trusty32"
  config.vm.hostname = "<put hostname here>"

  #Provision script - run once
  config.vm.provision "shell", path: "provision.sh"

end
