import sys
import requests
from bs4 import BeautifulSoup


def scrapePage(url):
    """ returns the html content of the url as a string """
    page = requests.get(url)
    soup = BeautifulSoup(page.content, 'html.parser')
    return str(soup.prettify())


def readFile(file):
    """ read the contents of the given file and return a string
        containing everything in the file """
    with open(file, 'r') as myfile:
        content=myfile.read().replace('\n', '')
    return content


def spaceTags(htmlString):
    """ returns html_string with spaces around every tag in htmlString """
    length = len(htmlString)
    index = 0
    spacedHtml = htmlString + " "
    while (index < length):
        if spacedHtml[index] == '<':
            # add space before tag
            spacedHtml =  spacedHtml[:index] + " " +  spacedHtml[index:]
            index += 2
            length += 1
        elif spacedHtml[index] == '>':
            # add space after tag
            spacedHtml =  spacedHtml[:index + 1] + " " +  spacedHtml[index + 1:]
            index += 2
            length += 1

        index += 1

    return  spacedHtml


def cleanTag(tag):
    """ cleans up a single tag
        ex: <div class="header"> becomes <div>
        ex: </div> stays </div> """
    cleanTag = ""
    length = len(tag)
    # turns <div class"header"> to <div
    for i in range(length):
        if tag[i] != " ":
            cleanTag += tag[i]
    cleanTag += ">"
    return cleanTag


def cleanUpTags(htmlString):
    """ cleans up all tags in the htmlString by removing extra information
        ex: all <div class="header"> become <div>
        ex: all </div> stay </div> """
    cleanHtml = ""
    inDiv = False
    onDiv = False
    length = len(htmlString)
    i = 0
    while (i < length):
        if inDiv:
            if htmlString[i] == ' ':
                onDiv = False
            elif htmlString[i] == '>':
                inDiv = False
                cleanHtml += htmlString[i]
            elif onDiv:
                cleanHtml += htmlString[i]
        else:
            if htmlString[i] == '<':
                inDiv = True
                onDiv = True
            cleanHtml += htmlString[i]
        i += 1

    return cleanHtml


def format(htmlString):
    pageContent = scrapePage(url)
    pageContent = spaceTags(pageContent)
    pageContent = cleanUpTags(pageContent)
    return pageContent


inputType = sys.argv[2] # url or file
pageContent = ""

if inputType == "url":
    url = sys.argv[1]
    pageContent = format(scrapePage(input))
else:
    file = sys.argv[1]
    pageContent = format(readFile(file))

with open(contentFile, 'w') as content:
    content.write(pageContent)
