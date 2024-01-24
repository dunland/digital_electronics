## Installation
https://gencaster.org/
https://docs.gencaster.org/tutorial.html
https://docs.gencaster.org/deployment.html#deployment
https://github.com/Gencaster/gencaster
Email: contact@gencaster.org

```bash
git clone git@github.com:gencaster/gencaster.git
cd gencaster
python3 -m venv ~/python/venv/gencaster  # create venv
source ~/python/venv/gencaster/bin activate  # activate venv
pip3 install pre-commit
touch .secrets.env
sudo apt install docker.io
make docker-local  # unknown shorthand flag 'f' in -f
sudo apt install docker-compose  # https://github.com/docker/compose/issues/8986
make docker-local  # after replacing -f flags: compose is not a docker command
```

