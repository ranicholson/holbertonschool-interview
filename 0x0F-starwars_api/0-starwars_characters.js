#!/usr/bin/node

const request = require('request');
const movieNumber = parseInt(process.argv[2]);
const url = 'https://swapi-api.hbtn.io/api/films/' + movieNumber;

request(url, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const bodyShot = JSON.parse(body);

    for (const character of bodyShot.characters) {
      request(character, function (err, resp, bod) {
        if (err) {
          console.log(err);
        } else {
          console.log(JSON.parse(bod).name);
        }
      });
    }
  }
});
