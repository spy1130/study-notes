# 导入必要的库
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
from matplotlib.patches import Circle

# 定义组合体的基本几何体参数
r1 = 4  # 球体的半径
r2 = 2  # 长方体的边长
h1 = 10  # 圆柱体的高度
h2 = 6  # 圆锥体的高度

# 定义圆柱体的底部圆形
circle1 = Circle((0, 0), r1, color='gray', alpha=0.5)

# 定义两个长方体的底部面
rect1 = [(0, -r1), (0, -r1-h2), (-r2, -r1-h2), (-r2, -r1)]
rect2 = [(0, -r1), (0, -r1-h2), (r2, -r1-h2), (r2, -r1)]
rect1_face = Poly3DCollection([rect1], alpha=0.5, facecolor='gray')
rect2_face = Poly3DCollection([rect2], alpha=0.5, facecolor='gray')

# 定义左视图的范围和坐标轴名称
plt.xlim(-r1-r2, r1)
plt.ylim(-r1-h2, h1)
plt.xlabel('X')
plt.ylabel('Z')

# 添加底部圆形和底部面到图中
plt.gca().add_patch(circle1)
plt.gca().add_collection(rect1_face)
plt.gca().add_collection(rect2_face)

# 显示图形
plt.show()
