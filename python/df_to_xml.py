import pandas as pd

def to_xml(row):
    xml = ['<item>']
    for field in row.index:
        xml.append('  <field name="{0}">{1}</field>'.format(field, row[field]))
    xml.append('</item>')
    return '\n'.join(xml)

df = pd.DataFrame.from_dict({'col_1': [1,4,6], 'col_2': [7,8,9]})

print('\n'.join(df.apply(to_xml, axis=1)))