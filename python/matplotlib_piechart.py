import matplotlib.pyplot as plt

# Pie chart, where the slices will be ordered and plotted counter-clockwise:
labels = 'mix', 'fossil', '100% renewable'
sizes = [4, 73, 23]
explode = (0, 0.1, 0)  # only "explode" the 2nd slice (i.e. 'Hogs')
colors = [(0.8, 0.71, 0.43), (106/255, 106
                              / 255, 106/255), (24/255, 172/255, 34/255)]

fig1, ax1 = plt.subplots()
ax1.pie(sizes, explode=explode, autopct='%1.1f%%',
        shadow=True, startangle=90, colors=colors)
ax1.axis('equal')  # Equal aspect ratio ensures that pie is drawn as a circle.

plt.show()
