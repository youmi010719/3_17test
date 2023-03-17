#层次聚类算法
from sklearn import datasets
from sklearn.cluster import AgglomerativeClustering
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix
import pandas as pd
from sklearn.preprocessing import StandardScaler
BuddyMove = pd.read_csv('./buddymove_holidayiq.csv')
BMdata = BuddyMove.to_numpy()[:, :]
# transfer = StandardScaler()
# BMdata = transfer.fit_transform(BMdata)

#n_ clusters表示聚类个数, linkagea表示距高度量函数,其中ward是最小距离、 complete是最大距离、 average是平均距离
#测试不同的结果,只需替换一下就可以了
clustering = AgglomerativeClustering(linkage='ward', n_clusters=3)
res = clustering.fit(BMdata[:, 1:])
print("各个簇的样本数目:")
print(pd.Series(clustering.labels_).value_counts())
print("聚类结果:")
print(confusion_matrix(BMdata[:, 1], clustering. labels_))
plt.figure()
d0 = BMdata[clustering.labels_ == 0]
plt.plot(d0[:,0],d0[:,1],'r.')
d1 = BMdata[clustering. labels_ == 1]
plt.plot(d1[:,0],d1[:,1],'go')
d2 = BMdata[clustering. labels_ == 2]
plt.plot(d2[:,0],d2[:,1],'b*')
plt.xlabel( "Sepal. Length")
plt.ylabel("SepaL. Width")
plt.title("AGNES Clustering")
plt.show()