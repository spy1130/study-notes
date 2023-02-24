#!/usr/bin/python
#encoding=utf-8
 
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()
import numpy as np
import matplotlib.pyplot as plt
 
learn_rate = 0.01
 
#y=2x+4
#随机生成y=2x+4的一些坐标点
train_X = [9.3,13.7,21.3,27.7,31.7,35.7,42.3,46.9,52.3,58.3,61.1]
train_Y = [78.2834,115.627,180.21,234.654,268.63,302.619,358.752,397.854,443.751,494.749,518.51]
 
#转成成numpy数组
train_X = np.array(train_X)
train_Y = np.array(train_Y)
n_samples = train_X.shape[0]
 
#用placeholder定义X和Y变量，具体值在训练的是用feed_dict填充
X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)
 
#定义初始化W和b，一般不建议置0，用随机值初始化
W = tf.Variable(np.random.random(), name="weigth")
b = tf.Variable(np.random.random(), name="bias")
 
#带预测的线性方程
prediction = tf.add(tf.multiply(X, W), b)
 
#用最小二乘定义损失函数
cost = tf.reduce_mean(tf.square(prediction - Y))
 
#这里优化器并没有用梯度下降，而用的是Adam优化器，后面说明，优化，使得cost最小
#optimizer = tf.train.GradientDescentOptimizer(learn_rate).minimize(cost)
optimizer = tf.train.AdamOptimizer(learn_rate).minimize(cost)
 
init = tf.global_variables_initializer()
 
with tf.Session() as sess:
    sess.run(init)
    for i in range(1000):
        for (x, y) in zip(train_X, train_Y):
            #执行定义的优化器，填充placeholder定义的变量
            sess.run(optimizer, feed_dict={X:x, Y:y})
 
        if i % 50 == 0:
            #每隔50次打印一次cost，由于cost依赖X和Y，所以也需要用feed_dict填充
            c = sess.run(cost, feed_dict={X: train_X, Y: train_Y})
            print("Epoch:", '%04d' % i, "cost=", "{:.9f}".format(c), "W=", sess.run(W), "b=", sess.run(b))
 
    print("Optimization Finished!")
 
    training_cost = sess.run(cost, feed_dict={X: train_X, Y: train_Y})
    print("Training cost=", training_cost, "W=", sess.run(W), "b=", sess.run(b))
 
    plt.plot(train_X, train_Y, 'ro', label="origal data")
    plt.plot(train_X, sess.run(W) * train_X + sess.run(b), label="fit line")
    plt.legend()
    plt.show()