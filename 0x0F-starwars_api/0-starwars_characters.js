#!/usr/bin/node

const request = require('request');
const movieNumber = parseInt(process.argv[2]);
const url = 'https://swapi-api.hbtn.io/api/films/' + movieNumber + '/';

request(url, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const bodyShot = JSON.parse(body).characters;
    const characterList = {};

    bodyShot.forEach(character => {
      request(character, function (error, response, body) {
        if (error) {
          console.log(error);
        }
        const name = JSON.parse(body).name;
        characterList[character] = name;
        if (Object.values(characterList).length === bodyShot.length) {
          bodyShot.forEach(character => {
            console.log(characterList[character]);
          });
        }
      });
    });
  }
});
