FROM node:19-alpine

WORKDIR /app

RUN apk update && apk upgrade
RUN apk add git

# dependencies

COPY ./package*.json /app/

RUN npm install && npm cache clean --force

COPY . .

ENV PATH ./node_modules/.bin/:$PATH