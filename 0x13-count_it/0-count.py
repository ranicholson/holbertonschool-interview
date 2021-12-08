#!/usr/bin/python3
"""Function to use API to list top 10 hot posts of a subreddit"""

import ast
import requests


def count_words(subreddit, word_list, after=None, wordDictionary={}):
    """Function to get subreddit user count"""
    user_agent = {
     "User-Agent": "StrangerDanger"
    }
    parameters = {
        "limit": 100
    }
    target_url = "https://www.reddit.com/r/" + subreddit\
        + "/hot.json?after=" + str(after)
    r = requests.get(target_url, headers=user_agent, params=parameters,
                     allow_redirects=False)

    if wordDictionary == {}:
        wordDictionary = dict.fromkeys(word_list, 0)

    if r.status_code == 200:
        hot_post_list = []
        hot_post = r.json().get("data").get("children")
        for post in hot_post:
            title = post.get("data").get("title").lower().split()
            for word in wordDictionary:
                wordDictionary[word] += title.count(word.lower())
        after = (r.json().get("data").get("after"))
        if after is None:
            LngFrPEP8 = sorted(wordDictionary.items(), key=lambda x: x[::-1])
            sortWrdList = sorted(LngFrPEP8, key=lambda y: y[1], reverse=True)
            for word, count in sortWrdList:
                if count != 0:
                    print("{}: {}".format(word.lower(), count))
            return
        return (count_words(subreddit, word_list, after, wordDictionary))
    else:
        return (None)
