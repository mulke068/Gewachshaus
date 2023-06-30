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


# License

       Copyright 2023 the original author or authors.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

