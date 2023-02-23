import urllib.request
import chardet#检测编码

def main():
    url = input("请输入URL：")

    response = urllib.request.urlopen(url)
    html = response.read()

    # 识别网页编码
    encode = chardet.detect(html)['encoding']#chardet.detect(html)={'encoding': '***', 'confidence': number, 'language': ''}
    if encode == 'GB2312':#GBK是GB2312的超集，两者是同一种编码
        encode = 'GBK'

    print("该网页使用的编码是：%s" % encode)
        
if __name__ == "__main__":
    main()