# parser.py (используем requests + BeautifulSoup)
import requests
from bs4 import BeautifulSoup
import json
import sys

def parse_dixy(product_name):
    url = f"https://www.dixy.ru/search?q={product_name}"
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    
    products = []
    for item in soup.select('.product-card'):  # (Пример, классы надо уточнить)
        name = item.select_one('.product-name').text
        price = float(item.select_one('.price').text.replace('₽', '').strip())
        weight = item.select_one('.weight').text  # "1 л" → 1000 (г)
        products.append({"name": name, "price": price, "weight": weight})
    
    return products

if __name__ == "__main__":
    product = sys.argv[1]  # Получаем аргумент из C++
    results = parse_dixy(product)
    print(json.dumps(results))  # Вывод в JSON для C++