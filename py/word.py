import os
from docx import Document
from docx.shared import Pt
from docx.oxml.ns import qn
from docx.oxml import OxmlElement

def set_heading_format(doc, level, font_name, font_size):
    # 获取指定级别的标题样式
    heading_style = doc.styles[level]
    
    # 修改样式的XML元素
    xml = heading_style._element
    # 设置字体名称
    xml.rPr.rFonts.set(qn('w:eastAsia'), font_name)
    # 设置字体大小
    size = OxmlElement('w:sz')
    size.set(qn('w:val'), str(font_size * 2))  # Word文档中的大小是实际大小的两倍
    xml.rPr.append(size)
    size_cs = OxmlElement('w:szCs')
    size_cs.set(qn('w:val'), str(font_size * 2))  # Word文档中的大小是实际大小的两倍
    xml.rPr.append(size_cs)

def process_document(doc_path):
    if not os.path.exists(doc_path):
        print(f"文件不存在: {doc_path}")
        return
    
    # 打开文档
    doc = Document(doc_path)
    
    # 设置一级标题样式
    set_heading_format(doc, 'Heading 1', '关于睡眠和运动', 16)  # 16磅
    # 设置二级标题样式
    set_heading_format(doc, 'Heading 2', '关于睡眠', 14)  # 14磅

    # 保存文档
    doc.save(doc_path)

# 指定文档路径
doc_path = r'F:\Desktop\这是关于运动和睡眠.docx'
process_document(doc_path)