import mechanize, re, sys
from mechanize import Browser
from bs4 import BeautifulSoup


if(len(sys.argv) < 2):
    print "Please enter the make model and year of your vehicle surrounded by \"\""
    exit(0)
if(len(sys.argv[1]) < 5):
    print "You must surround the make model and vehicle in quotes"
    exit(0)


searchGoogle = mechanize.Browser()
searchGoogle.set_handle_robots(False)
searchGoogle.addheaders = [('User-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1')]
searchGoogle.open('https://www.google.com/')

searchGoogle.select_form(nr=0)
searchGoogle['q'] = sys.argv[1] + " gas tank size"
html = searchGoogle.submit()

soup = BeautifulSoup(html, "html5lib")
info = soup.find_all("div")

hasFuelInfo = []
for blah in info:
    if "Fuel" in blah.get_text():
        hasFuelInfo.append(blah.get_text())
        break
listofInfo = ''
try:
    listofInfo = re.split("\n+", hasFuelInfo[0])
except IndexError:
    print "Unable to find fuel tank size for: " + sys.argv[1]
    print "Make sure you entered make model and year in quotes"
    print "Example: \"Subaru Outback 2014\""
    exit(0)

hasFuelInfo = ''
foundmark = False
for blah in listofInfo:
    if "Fuel tank." in blah or "Fuel Capacity." in blah or "Fuel tank capacity:" in blah:
        listout = re.split("\\s+", blah);
        for hi in listout:
            if hi == "tank." or hi == "Capacity." or hi == "capacity:":
                foundmark = True
                continue
            if foundmark:
                hasFuelInfo = (re.findall('\d+', hi))
                break
        break

fuelTankSize = ''
for blah in hasFuelInfo:
    fuelTankSize += blah + '.'
if fuelTankSize == '':
    print "Unable to find fuel tank size for: " + sys.argv[1]
    print "Make sure you entered make model and year in quotes"
    print "Example: \"Subaru Outback 2014\""
    exit(0)
else:
    print fuelTankSize[:-1]
