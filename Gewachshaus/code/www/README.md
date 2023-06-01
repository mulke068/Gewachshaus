## Requirements for running the code

```
- Node 18.15.0
- NPM 9.5.6
- Yarn 1.22.19
- Docker 20.10.23
- Docker-Compose 2.15.1
```

## How to run the code

```bash
# Install dependencies
npm install
```

## How to run the code with docker-compose

```bash
# Run the app
docker-compose up
```
## Docker Test
### docker-compose runs in detached mode and build the image and rebuild the image if the Dockerfile changes and remove the containers when the app is stopped

```bash
# Run the app
docker-compose up -d --build --force-recreate --remove-orphans
```