import webbrowser

url = "https://www.example.com"
chrome_path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
webbrowser.get(chrome_path).open(url)



from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
import time

chrome_driver_path = r"C:\Users\sahak\Downloads\chromedriver-win64 (3)\chromedriver-win64\chromedriver.exe"

chrome_options = Options()
chrome_options.add_experimental_option("excludeSwitches", ["enable-automation"])
chrome_options.add_experimental_option("useAutomationExtension", False)
chrome_options.add_argument("--disable-blink-features=AutomationControlled")
chrome_options.add_argument("--log-level=3")

# Use a separate Selenium-only profile to avoid conflict
chrome_options.add_argument(r"user-data-dir=C:\Users\sahak\AppData\Local\Google\Chrome\User Data\SeleniumProfile")

service = Service(chrome_driver_path)
driver = webdriver.Chrome(service=service, options=chrome_options)

driver.get("https://subdomainfinder.c99.nl/")
time.sleep(5)

search_box = driver.find_element(By.NAME, "q")
search_box.send_keys("OpenAI GPT-4")
search_box.send_keys(Keys.RETURN)

time.sleep(5)
driver.quit()
