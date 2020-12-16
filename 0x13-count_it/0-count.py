#!/usr/bin/python3
"""
Count it!
"""
import requests


def recursive_count(subreddit, word_list, titles, after=None):
    """
    Recursive function that queries the Reddit API,
    parses the title of all hot articles, and prints
    a sorted count of given keywords
    """
    url = "https://www.reddit.com/r/{}/hot.json?after={}".format(subreddit,
                                                                 after)
    res = requests.get(url,
                       headers={'User-agent': 'product'},
                       allow_redirects=False)

    if res.status_code != 200:
        return None
    if after is None:
        return titles

    for i in res.json().get('data').get('children'):
        title_s = i.get('data').get('title').split()
        for word in set(word_list):
            if word.lower() in [x.lower() for x in title_s]:
                if titles.get(word):
                    titles[word] += 1
                else:
                    titles[word] = 1

    after = res.json().get('data').get('after')
    recursive_count(subreddit, word_list, titles, after)
    return titles


def count_words(subreddit, word_list):
    """
    Function that queries the Reddit API,
    parses the title of all hot articles, and prints
    a sorted count of given keywords
    """
    titles = recursive_count(subreddit, word_list, {})
    if titles:
        for k, v in sorted(titles.items(), key=lambda val: val[1],
                           reverse=True):
            if v != 0:
                print('{}: {}'.format(k, v))
