# JavaSE

本篇用于记录，在学习了 C 和 Python 的语法基础下，学习 Java 的**自认为不同于前两门语言而需要记录**的内容，仅含概 **JavaSE** 部分内容，用于个人参考和回顾。**由于每个人的学习进度不同，所以不建议用于自学。**



## 一、手动运行代码

1. 新建一个目录src，存放源代码，再写一个简单的HelloWorld类，如下：

    ```java
    public static void main(String[] args) {
    	System.out.println("HelloWorld");
    	}
    }
    ```

​		目录如下：

​		![目录](https://img-blog.csdnimg.cn/20210203195017310.png)

2. 编译并运行代码

    - 进入src所在目录，并选择在此处打开命令窗口
	- 依次输入 `javac HelloWorld.java` ，`java HelloWorld`，编译运行代码，结果如下：
	
	    ![cmd](https://img-blog.csdnimg.cn/20210203195647715.jpg)
	
	    ​                               **注意，编译 class 文件时，不需要加后缀！**
	
	​	![result](https://img-blog.csdnimg.cn/20210203195910888.jpg)
	
3. **该操作仅为简单的运行步骤，只运行单个文件，且必须在源代码目录下操作**



## 二、Javadoc

Java 支持 3 种注释，分别是单行注释、多行注释和文档注释。文档注释以`/**`开头，并以`*/`结束，可以通过 Javadoc 生成 API 帮助文档，Java 帮助文档主要用来说明类、成员变量和方法的功能。



### 文档注释与Javadoc标签

如下即为文档注释，用于说明该类的相关信息，如：作者、参数、版本、异常等。

```java
/**
* @author :作者名
* @version :版本号
* @since :指明最早需要使用的jdk版本
* @param ：参数
* @return:返回值情况
* @throws:异常抛出情况
*/
public class Test {
    /**
     * 求输入两个参数范围以内整数的和
     * @param n 接收的第一个参数，范围起点
     * @param m 接收的第二个参数，范围终点
     * @return 两个参数范围以内整数的和
     */
    public int add(int n, int m) {
        int sum = 0;
        for (int i = n; i <= m; i++) {
            sum = sum + i;
        }
        return sum;
    }
} 
```

上述中存在的关键词则是文档注释中Javadoc 工具可以识别的一些特殊标签，这些标签一般以`@`开头，后跟一个指定的名字，有的也以`{@`开头，以`}`结束。Javadoc 可以识别的标签如下表所示：

| 标签          | 描述                                                   | 示例                                                         |
| ------------- | ------------------------------------------------------ | ------------------------------------------------------------ |
| @author       | 标识一个类的作者，一般用于类注释                       | @author description                                          |
| @deprecated   | 指名一个过期的类或成员，表明该类或方法不建议使用       | @deprecated description                                      |
| {@docRoot}    | 指明当前文档根目录的路径                               | Directory Path                                               |
| @exception    | 可能抛出异常的说明，一般用于方法注释                   | @exception exception-name explanation                        |
| {@inheritDoc} | 从直接父类继承的注释                                   | Inherits a comment from the immediate surperclass.           |
| {@link}       | 插入一个到另一个主题的链接                             | {@link name text}                                            |
| {@linkplain}  | 插入一个到另一个主题的链接，但是该链接显示纯文本字体   | Inserts an in-line link to another topic.                    |
| @param        | 说明一个方法的参数，一般用于方法注释                   | @param parameter-name explanation                            |
| @return       | 说明返回值类型，一般用于方法注释，不能出现再构造方法中 | @return explanation                                          |
| @see          | 指定一个到另一个主题的链接                             | @see anchor                                                  |
| @serial       | 说明一个序列化属性                                     | @serial description                                          |
| @serialData   | 说明通过 writeObject() 和 writeExternal() 方法写的数据 | @serialData description                                      |
| @serialField  | 说明一个 ObjectStreamField 组件                        | @serialField name type description                           |
| @since        | 说明从哪个版本起开始有了这个函数                       | @since release                                               |
| @throws       | 和 @exception 标签一样.                                | The @throws tag has the same meaning as the @exception tag.  |
| {@value}      | 显示常量的值，该常量必须是 static 属性。               | Displays the value of a constant, which must be a static field. |
| @version      | 指定类的版本，一般用于类注释                           | @version info                                                |

**对两种标签格式的说明**：

- @tag 格式的标签（不被`{}`包围的标签）为块标签，只能在主要描述（类注释中对该类的详细说明为主要描述）后面的标签部分（如果块标签放在主要描述的前面，则生成 API 帮助文档时会检测不到主要描述）。

- {@tag} 格式的标签（由`{}`包围的标签）为内联标签，可以放在主要描述中的任何位置或块标签的注释中。

    

**注意事项**：

- Javadoc 标签必须从一行的开头开始，否则将被视为普通文本。

- 一般具有相同名称的标签放在一起。

- Javadoc 标签区分大小写，代码中对于大小写错误的标签不会发生编译错误，但是在生成 API 帮助文档时会检测不到该注释内容。



### 生成API帮助文档的简单步骤

Javadoc 用法格式如下：

```
javadoc [options] [packagenames] [sourcefiles]
```

对格式的说明：

- options 表示 Javadoc 命令的选项
- packagenames 表示包名
- sourcefiles 表示源文件名



以上述的`Test.java`为例，从该目录到开cmd后输入如下命令：

**输入命令时一定要加`-encoding UTF-8 -charset UTF-8`，否则可能会出现乱码**

```
javadoc -author -version Test.java
```

![cmd](http://c.biancheng.net/uploads/allimg/191030/5-19103013361Q14.png)	

打开 `Test.java `文件存储的位置，会发现多出了一个 `Test.html `文档。打开文档，文档页面如下图所示。

![img1](http://c.biancheng.net/uploads/allimg/191030/5-1910301340249B.png)	

下图是方法说明

![img2](http://c.biancheng.net/uploads/allimg/191030/5-19103013403LC.png)
**以上命令未考虑编码格式，汉字可能会乱码。使用`javadoc -encoding UTF-8 -charset UTF-8 Test.java`会解决编码问题。**



## 三、新增数据类型

相较于 C 和 Python ，Java 新增了一些数据类型和表达方式，现记录说明。



### 基本数据类型

- byte：关键字之一，占1个字节，用于对位的操作，使用前需声明

- 0b：用于表达二进制数据的表达方式，如 `0b1011`

- BigDecimal：内置的大数**类**，用于储存和操作大数。这是个类，使用前需声明实例

- boolean：关键字之一，占1位，仅有 `true` 和 `false` 两个值，使用前需声明

    


### 引用数据类型

此处的引用可粗略理解为指针，也就是说该数据类型通过“指针”调用。该类型其实还包括**数组**，但不算新增，这里就不再赘述。

- 类：将同类对象的共同属性和行为抽象出来形成的一个相对复杂的数据类型，由**属性(变量)**和**方法(函数)**组成
- 接口：一个抽象类型，是抽象方法的集合，通常以`interface`来声明。一个类通过继承接口的方式，从而来继承接口的抽象方法。因此它**只能定义方法，而不能实现方法，方法的实现由子类通过重写完成**



### 注意事项

- 在 Java 中，**没有 `long long` 长长整型**， 且定义 `long` 长整型数据和 `float` 浮点数需要在数值末尾分别加上一个 `L` 和 `F` ，如下：
    ```java
    long a = 100000L; float b = -200000F; // L & F理论上不分大小写，但通常情况大写比较规范且易分辨
    ```


- 在 Java 中，基本数据类型未初始化时，默认值为**0**；引用数据类型未初始化时，默认值为**null**

- 在 Java 中，所有逻辑判断都必须使用布尔值，如 if 语句和循环的条件等，不能将其他数据类型放入其中，如下：

    ```java
    int a = 1; boolean b = true;
    if (b) {...} // 正确用法
    if (a) {...} // 错误用法，应该为 if (a == 1) {...}
    ```

    

## 四、类名与包机制

Java 中，万物皆对象。



### 类名

一个 `Java` 文件被称作一个Java类，**每个Java文件内部的唯一公开类名必须与文件名相同**，比如下面的 `CalculatePrime.java `文件。



### 包机制

Java 中使用 `package` 语句定义包，可以粗略地理解为文件夹，**`package` 语句应该放在源文件的第一行，在每个源文件中只能有一个包定义语句**，并且 `package` 语句适用于所有类型（类、接口、枚举和注释）的文件。如下图所示：

![包1](D:\ShowTime\Note\Picture\包1.png)

上图中的工作环境根目录为 `src` 文件夹，所以 `Test.java` 无需写明包路径，而 `CalculatePrime.java ` 则需要写一个文件夹名。包的作用是把不同的程序分类保存，更方便的被其他程序调用。

我们还可以通过导入包来访问其他类，使用 `import` 来实现，下图是在 `Test.java` 中导入 `Code` 里的 `CalculatePrime` 类：

![import](D:\ShowTime\Note\Picture\包2.png)

如果上述包中的类太多，还可以用 `import Code.*` 来导入全部类。***注：同一目录下的类之间可相互直接访问，因为在同一包下。***

---

**包的命名规则：**

- 包名全部由小写字母（多个单词也全部小写）。
- 如果包名包含多个层次，每个层次用 `.` 分割。
- 包名一般由倒置的域名开头，比如 com.baidu，不要有 www。
- 自定义包不能 `java` 开头。

*注：如果在源文件中没有定义包，那么类、接口、枚举和注释类型文件将会被放进一个无名的包中，也称为默认包。在实际企业开发中，通常不会把类定义在默认包下。*

---

**常见的系统包**：

- java.lang：系统常用基础类(String、Object),此包从 JDK 1.1 后自动导入。
- java.lang.reflect：java 反射编程包;
- java.net：进行网络编程开发包。
- java.sql：进行数据库开发的支持包。
- java.util：是 java 提供的工具程序包。(集合类等) 非常重要
- java.io：I/O 编程开发包



## 五、命名规则

命名规则只是人为定义的一种规范，具体如下：

-  包：由小写英文字母组成，具体如上文所述
-  类&接口：所有单词首字母大写，例如 `ThreadDemo1`
-  方法&变量：首字母必须小写，如果该变量名有多个单词组成，后面的单词首字母大写，单词与单词之间通常不使用 `_` 做连接
-  常量：单个单词组成，全部大写，多个单词组成，单词全部大写，并用 `_` 连接



## 六、字符串

与 C 不同的是，Java 提供了 String ，StringBuilder ，StringBuffer 三个类来专门处理字符串，在 Java 中字符串属于对象，而不是基本数据类型之一。



### String 类

---

#### 创建字符串

创建字符串最简单的方式如下:

```java
String str = "Runoob";
```

这里的值是 "Runoob"，编译器会使用该值创建一个 String 对象。

和其它对象一样，可以使用关键字和构造方法来创建 String 对象：

```java
String str2 = new String("Runoob");
```

String 创建的字符串存储在公共池中，而 `new` 创建的字符串对象在堆上：

```java
String s1 = "Runoob";              // String 直接创建
String s2 = "Runoob";              // String 直接创建
String s3 = s1;                    // 相同引用
String s4 = new String("Runoob");   // String 对象创建
String s5 = new String("Runoob");   // String 对象创建
```

![img](https://www.runoob.com/wp-content/uploads/2013/12/java-string-1-2020-12-01.png)

String 类有 11 种构造方法，这些方法提供不同的参数来初始化字符串，比如提供一个字符数组参数:

```java
public class StringDemo{
   public static void main(String args[]){
      char[] helloArray = { 'r', 'u', 'n', 'o', 'o', 'b'};
      String helloString = new String(helloArray);  
      System.out.println( helloString ); // 输出结果为：runoob
   }
}
```

**注意：**String 类是不可改变的，它是**字符串常量**，所以你一旦创建了 String 对象，那它的值就无法改变了。

如果需要对字符串做很多修改，那么应该选择使用 [StringBuffer & StringBuilder 类](https://www.runoob.com/java/java-stringbuffer.html)。

---

#### 字符串长度

String 类提供了一个 `length` 方法，用来返回字符串对象包含的字符数，如下所示:

```java
public class StringDemo {
    public static void main(String args[]) {
        String site = "www.runoob.com";
        int len = site.length();
        System.out.println( "菜鸟教程网址长度 : " + len ); // 输出结果为：菜鸟教程网址长度 : 14
   }
}
```

---

#### 连接字符串

String 类提供了连接两个字符串的方法：

```java
string1.concat(string2);
```

返回 `string2` 连接 `string1` 的新字符串。也可以对字符串常量使用 `concat` 方法，如：

```java
"我的名字是 ".concat("Runoob"); // "我的名字是 Runoob"
```

更常用的是使用'+'操作符来连接字符串，如：

```java
"Hello," + " runoob" + "!" // "Hello, runoob!" 
```

下面是一个例子:

```java
public class StringDemo {
    public static void main(String args[]) {     
        String string1 = "菜鸟教程网址：";     
        System.out.println("1、" + string1 + "www.runoob.com"); // 输出结果为：1、菜鸟教程网址：www.runoob.com
    }
}
```

---

#### 创建格式化字符串

我们知道输出格式化数字可以使用 `printf` 和 `format` 方法。

String 类使用静态方法 `format` 返回一个 String 对象而不是 PrintStream 对象。

该静态方法能用来创建可复用的格式化字符串，而不仅仅是用于一次打印输出。

如下所示：

```java
System.out.printf("%f, %d, %s", floatVar, intVar, stringVar);
```

你也可以这样写

```java
String fs = String.format("%f, %d, %s", floatVar, intVar, stringVar);
```

---

#### String 方法

下面是常用 String 类支持的方法，包含重载方法，更多详细请参看 [Java String API](https://www.runoob.com/manual/jdk11api/java.base/java/lang/String.html) 文档：

| *    | 方法描述                                                     |
| :--- | :----------------------------------------------------------- |
| 1    | **char charAt(int index)** 返回指定索引处的 char 值。        |
| 2    | **String concat(String str)** 将指定字符串连接到此字符串的结尾。 |
| 3    | **boolean endsWith(String suffix)** 测试此字符串是否以指定的后缀结束。 |
| 4    | **boolean equals(Object anObject)** 将此字符串与指定的对象比较。 |
| 5    | **void getChars(int srcBegin, int srcEnd, char dst, int dstBegin)** 将字符从此字符串复制到目标字符数组。 |
| 6    | **int indexOf(int ch)** 返回指定字符在此字符串中第一次出现处的索引。 |
| 7    | **int indexOf(int ch, int fromIndex)** 返回在此字符串中第一次出现指定字符处的索引，从指定的索引开始搜索。 |
| 8    | **int indexOf(String str)**  返回指定子字符串在此字符串中第一次出现处的索引。 |
| 9    | **int indexOf(String str, int fromIndex)** 返回指定子字符串在此字符串中第一次出现处的索引，从指定的索引开始。 |
| 10   | **int lastIndexOf(int ch)**  返回指定字符在此字符串中最后一次出现处的索引。 |
| 11   | **int lastIndexOf(int ch, int fromIndex)** 返回指定字符在此字符串中最后一次出现处的索引，从指定的索引处开始反向搜索。 |
| 12   | **int lastIndexOf(String str)** 返回指定子字符串在此字符串中最右边出现处的索引。 |
| 13   | **int lastIndexOf(String str, int fromIndex)**  返回指定子字符串在此字符串中最后一次出现处的索引，从指定的索引开始反向搜索。 |
| 14   | **int length()** 返回此字符串的长度。                        |
| 15   | **boolean matches(String regex)** 告知此字符串是否匹配给定的正则表达式。 |
| 16   | **String replace(char oldChar, char newChar)** 返回一个新的字符串，它是通过用 newChar 替换此字符串中出现的所有 oldChar 得到的。 |
| 17   | **String replaceAll(String regex, String replacement)** 使用给定的 replacement 替换此字符串所有匹配给定的正则表达式的子字符串。 |
| 18   | **String replaceFirst(String regex, String replacement)** 使用给定的 replacement 替换此字符串匹配给定的正则表达式的第一个子字符串。 |
| 19   | **String[] split(String regex)** 根据给定正则表达式的匹配拆分此字符串。 |
| 20   | **String[] split(String regex, int limit)** 根据匹配给定的正则表达式来拆分此字符串。 |
| 21   | **boolean startsWith(String prefix)** 测试此字符串是否以指定的前缀开始。 |
| 22   | **boolean startsWith(String prefix, int toffset)** 测试此字符串从指定索引开始的子字符串是否以指定前缀开始。 |
| 23   | **String substring(int beginIndex)** 返回一个新的字符串，它是从指定下标开始一直截取到字符串的最后。 |
| 24   | **String substring(int beginIndex, int endIndex)** 返回一个新字符串，它是从前一个下标截取到后一个下标对应的元素。 |
| 25   | **char[] toCharArray()** 将此字符串转换为一个新的字符数组。  |
| 26   | **String toLowerCase()** 使用默认语言环境的规则将此 String 中的所有字符都转换为小写。 |
| 27   | **String toLowerCase(Locale locale)** 使用给定 Locale 的规则将此 String 中的所有字符都转换为小写。 |
| 28   | **String toString()** 返回此对象本身（它已经是一个字符串！）。 |
| 29   | **String toUpperCase()** 使用默认语言环境的规则将此 String 中的所有字符都转换为大写。 |
| 30   | **String toUpperCase(Locale locale)** 使用给定 Locale 的规则将此 String 中的所有字符都转换为大写。 |
| 31   | **String trim()** 返回字符串的副本，忽略前导空白和尾部空白。 |
| 32   | **contains(CharSequence chars)** 判断是否包含指定的字符系列。 |
| 33   | **isEmpty()** 判断字符串是否为空。                           |



### StringBuffer & StringBuilder 

当对字符串进行修改的时候，需要使用 StringBuffer 和 StringBuilder 类，它们能够被多次的修改，并且不产生新的未使用对象。

由于 StringBuilder 相较于 StringBuffer 有速度优势，所以多数情况下建议使用 StringBuilder 类。

```java
public class Test {
    public static void main(String args[]) {
        StringBuilder sb = new StringBuilder(10); // 相当于创建一个长度为10的字符数组
        sb.append("Runoob.."); // 追加
        System.out.println(sb);  
        sb.append("!");
        System.out.println(sb); 
        sb.insert(8, "Java"); // 利用索引插入
        System.out.println(sb); 
        sb.delete(5,8);
        System.out.println(sb); // 利用索引删除
    }
}
```

然而在应用程序要求线程安全的情况下，则必须使用 StringBuffer 类。

```java
public class Test{
  public static void main(String args[]){
    StringBuffer sBuffer = new StringBuffer("菜鸟教程官网：");
    sBuffer.append("www");
    sBuffer.append(".runoob");
    sBuffer.append(".com");
    System.out.println(sBuffer);  
  }
}
```

以下是 StringBuffer 类支持的主要方法：

| *    | 方法描述                                                     |
| :--- | :----------------------------------------------------------- |
| 1    | **public StringBuffer append(String s)** 将指定的字符串追加到此字符序列。 |
| 2    | **public StringBuffer reverse()**  将此字符序列用其反转形式取代。 |
| 3    | **public delete(int start, int end)** 移除此序列的子字符串中的字符。 |
| 4    | **public insert(int offset, int i)** 将 `int` 参数的字符串表示形式插入此序列中。 |
| 5    | **insert(int offset, String str)** 将 `str` 参数的字符串插入此序列中。 |
| 6    | **replace(int start, int end, String str)** 使用给定 `String` 中的字符替换此序列的子字符串中的字符。 |

以下列表列出了 StringBuffer 类的其他常用方法：

| *    | 方法描述                                                     |
| :--- | :----------------------------------------------------------- |
| 1    | **int capacity()** 返回当前容量。                            |
| 2    | **char charAt(int index)** 返回此序列中指定索引处的 `char` 值。 |
| 3    | **void ensureCapacity(int minimumCapacity)** 确保容量至少等于指定的最小值。 |
| 4    | **void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)** 将字符从此序列复制到目标字符数组 `dst`。 |
| 5    | **int indexOf(String str)** 返回第一次出现的指定子字符串在该字符串中的索引。 |
| 6    | **int indexOf(String str, int fromIndex)** 从指定的索引处开始，返回第一次出现的指定子字符串在该字符串中的索引。 |
| 7    | **int lastIndexOf(String str)** 返回最右边出现的指定子字符串在此字符串中的索引。 |
| 8    | **int lastIndexOf(String str, int fromIndex)** 返回 String 对象中子字符串最后出现的位置。 |
| 9    | **int length()** 返回长度（字符数）。                        |
| 10   | **void setCharAt(int index, char ch)** 将给定索引处的字符设置为 `ch`。 |
| 11   | **void setLength(int newLength)** 设置字符序列的长度。       |
| 12   | **CharSequence subSequence(int start, int end)** 返回一个新的字符序列，该字符序列是此序列的子序列。 |
| 13   | **String substring(int start)** 返回一个新的 `String`，它包含此字符序列当前所包含的字符子序列。 |
| 14   | **String substring(int start, int end)** 返回一个新的 `String`，它包含此序列当前所包含的字符子序列。 |
| 15   | **String toString()** 返回此序列中数据的字符串表示形式。     |



## 七、用户输入

在 Java 当中，我们可以通过 导入`Scanner` 类来获取用户的输入。

```java
Scanner s = new Scanner(System.in);
```
通过 `Scanner` 类的 `next()` 与 `nextLine()` 方法获取输入的字符串，在读取前我们一般需要使用 `hasNext()` 和 `hasNextLine()` 判断是否还有输入的数据。

```java
import java.util.Scanner; // 使用前记得导入

public class Demo1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        if(input.hasNext()) // 判断是否还有输入的数据
        {
            String str = input.next(); // String str = input.nextLine();
            System.out.println("输入的内容为" + str);
        }
        input.close(); // 在使用完后记得关闭
    }
}
```

两者的主要区别在于：

`next()`：要读取到有效字符后才可以结束输入，而对输入有效字符之前遇到的空白，它会自动将其去掉，只有输入有效字符后才将其后面输入的空白作为分隔符或者结束符。该方法不能得到带有空格的字符串。

`nextLine()`：以回车键为结束符，其返回的是输入回车之前的所有字符，因此该方法可以获得空白字符。

同理，`hasNext()` 和 `hasNextLine()` 也是一样。

除了以上两种基本的字符串判断方法，`Scanner` 还提供了其他类型数据的判断方法，如 `hasNextInt()` 、`hasNextFloat()` 等。



## 八、流程控制

在 Java 中，保留了 C/C++ 中的 `goto` 语句的特性，推出了带标签的 `break` 和 `countine` 语句，略有不同，在此记录。



### 带标签的 break
带标签的 `break` 语句通常用于多层循环嵌套中，在某一个循环前面加一个标签，如 `outer:` ，在需要退出循环的时候就可以直接用`break + 标签;` 跳出多层循环到标签处，**并且不会再次进入到刚才的循环中**。

```java
public class Test {
	public static void main(String[] args) {
		outer: // 这里是标签，跳转到这里，且不会再进入下面的循环
		for (int i = 1; i < 3; i++) {
			for (int j = 1; j < 3; j++) {
				for (int t = 1; t < 3; t++) {
					System.out.println("假期加油 " + t);
					break outer; // break + 标签
				}
			}
		}
		System.out.println("输出结束");
	}
}
```

运行结果如下：

```java
假期加油 1
输出结束
```



### 带标签的 countine

带标签的 `countine` 语句用法与 `break` 一样。不同的是，**跳转到标签处后，它会结束标签后面的当次循环，继续执行下一次循环**。

```java
public class Test {
	public static void main(String[] args) {
		label: // 这里是标签，跳转到这里，并结束下面的当次循环，继续执行下一次循环
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (j == 2) {continue label;} // countine + 标签
            	System.out.println(i + ", " + j);
            }
        }
	}
}
```

运行结果如下：

```
0, 0
0, 1
1, 0
1, 1
2, 0
2, 1
```



## 九、数组

在Java中，数组的声明和创建与C有些不同，所以这里单独来记录。



### 声明数组

首先必须声明数组变量，才能在程序中使用数组。下面是声明 `double` 数组变量的实例：

```java
double[] myList;         // 首选的方法
double myList[];         //  效果相同，但不是首选方法
```

**注意:** 建议使用 `dataType[] arrayRefVar` 的声明风格声明数组变量。 `dataType arrayRefVar[]` 风格是来自 C/C++ 语言 ，在Java中采用是为了让 C/C++ 程序员能够快速理解java语言。



### 创建数组

Java 语言使用 `new` 操作符来创建数组，语法如下：

```java
array = new int[10];
```

上面的语法语句做了两件事：

1. 使用 `int[10]` 创建了一个长度为10的整型数组。

2. 把新创建的数组的**引用**赋值给变量 `array` 。

数组的声明和创建也可以用一条语句完成，如下所示：

```java
int[] array = new int[10];
```

另外，你还可以使用如下的方式创建数组。

```java
int[] array = {1, 2, 3, 4, 5};
```



### 数组长度
在Java中，数组也是一个类，它拥有一个 `length` 属性来记录它的长度，这样便于处理数组，比如：

```java
// 打印所有数组元素
for (int i = 0; i < myList.length; i++) { // myList.length即是该数组的长度
	System.out.println(myList[i] + " ");
}
```



### 增强型 for 循环 (For-Each 循环)

Java5引入了一种主要用于数组的增强型 for 循环，与Python的 For-In 循环类似，其基本语法格式如下：

```java
for(声明语句 : 表达式) {
   //代码句子
}
```

**声明语句：**声明新的局部变量，该变量的类型必须和数组元素的类型匹配。其作用域限定在循环语句块，其值与此时数组元素的值相等。

**表达式：**表达式是要访问的数组名，或者是返回值为数组的方法。

---

实例如下：

```java
public class Test {
   public static void main(String[] args) {
      int [] numbers = {10, 20, 30, 40, 50};
 
      for(int x : numbers ) { // 每次循环都会将numbers数组的一个元素赋值给局部变量x
         System.out.print( x );
         System.out.print(",");
      }
      System.out.print("\n");
      String [] names ={"James", "Larry", "Tom", "Lacy"};
      for( String name : names ) { // 同理，这样便于操作数组元素
         System.out.print( name );
         System.out.print(",");
      }
   }
}
```

运行结果如下：

```
10,20,30,40,50,
James,Larry,Tom,Lacy,
```



### 其他不同点

整理一些与 C 仅有一点小差异的语法。

---

#### 数组作为函数的参数

```java
public static void printArray(int[] array) // 与声明时的写法一样
```

---

#### 多维数组的动态初始化

1. 声明后可以直接为每一维分配空间，如：

    ```java
    String[][] str = new String[3][4]; // 可以声明为基本数据类型或复合数据类型，且中括号内的长度必须为正整数
    ```

2. 也可以从最高维开始，分别为每一维分配空间，如：

    ```java
    String[][] s = new String[2][];
    s[0] = new String[2]; // 为第一维分配引用空间
    s[1] = new String[3]; // 为第二维分配引用空间
    s[0][0] = new String("Good");
    s[0][1] = new String("Luck");
    s[1][0] = new String("to");
    s[1][1] = new String("you");
    s[1][2] = new String("!");
    ```



### Arrays 类

`java.util.Arrays` 类能方便地操作数组，它提供的所有方法都是静态的。

具有以下常用功能：

- 给数组赋值：通过 `fill` 方法
- 对数组排序：通过 `sort` 方法,按升序
- 比较数组：通过 `equals` 方法比较数组中元素值是否相等
- 查找数组元素：通过 `binarySearch` 方法能对排序好的数组进行二分查找法操作

具体说明请查看下表：

|  *   | 方法和说明                                                   |
| :--: | :----------------------------------------------------------- |
|  1   | **public static int binarySearch(Object[] a, Object key)** 用二分查找算法在给定数组中搜索给定值的对象(`Byte`,`Int`,`double`等)。数组在调用前必须排序好的。如果查找值包含在数组中，则返回搜索键的索引；否则返回 (-(*插入点*) - 1)。 |
|  2   | **public static boolean equals(long[] a, long[] a2)** 如果两个指定的 `long` 型数组彼此*相等*，则返回 `true`。如果两个数组包含相同数量的元素，并且两个数组中的所有相应元素对都是相等的，则认为这两个数组是相等的。换句话说，如果两个数组以相同顺序包含相同的元素，则两个数组是相等的。同样的方法适用于所有的其他基本数据类型（`Byte`，`short`，`Int` 等）。 |
|  3   | **public static void fill(int[] a, int val)** 将指定的 `int` 值分配给指定 `int` 型数组指定范围中的每个元素。同样的方法适用于所有的其他基本数据类型（`Byte`，`short`，`Int` 等）。 |
|  4   | **public static void sort(Object[] a)** 对指定对象数组根据其元素的自然顺序进行升序排列。同样的方法适用于所有的其他基本数据类型（`Byte`，`short`，`Int` 等）。 |
|  5   | **public static String toString(int[] a)** 将指定 `int` 型数组的每个元素放在中括号内打印出来。其他基本数据类型同样适用。 |



## 十、类

面向对象编程 *(OOP)* 的核心，Java 作为一门纯OOP语言，它的类也与 Python 有些不同，故在此记录**不同之处**。



### 基本操作

- **声明**

    ```java
    [修饰符] class 类名 {...}
    ```
    
- **继承**

    ```java
    [修饰符] class 类名 extends 父类 {...} // 声明子类，只能单继承，父类后面可继续声明实现的接口
    ```
    
- **实现**

    ```java
    [修饰符] class 类名 implements 接口1, 接口2... {...} // 声明实现接口的类，可以“多继承”
    ```

- **实例化**

    ```java
    类名 实例名 = new 构造方法(); // 构造方法与类同名，若采用有参构造方法，则需传入参数
    ```

    

### 构造方法

也叫构造器，与 Python 类中的 `__init__` 功能类似，是一个对象被创建时，用来初始化该对象的方法。**构造方法和它所在类的名字相同，但构造方法没有返回值。**

下面是一个使用构造方法的例子：

```java
// 一个简单的构造函数，默认访问修饰符为default
class MyClass {
    int x;
 
    // 以下是构造函数，访问修饰符与类同为default，且没有声明返回值类型
    MyClass(int i) {
        x = i; // 构造方法常用来初始化变量，这里是直接访问类属性
    }
}
```

在没有显式定义构造方法的情况下，Java 自动提供了一个默认的无参构造方法，**默认构造方法的访问修饰符和类的访问修饰符相同**。

你可以像下面这样调用构造方法来初始化一个对象：

```java
public class ConsDemo {
    public static void main(String[] args) {
        MyClass t1 = new MyClass(10);
        MyClass t2 = new MyClass(20);
        System.out.println(t1.x + " " + t2.x); // 输出结果为：10 20
    }
}
```

***注：一旦你定义了自己的构造方法，默认构造方法就会失效。***

---

#### this 关键字

上述代码定义的方法可以直接访问变量，但如果方法里有个局部变量和静态变量同名，但程序又需要在该方法里访问这个被覆盖的静态变量，则必须使用 `this` 前缀，这个与 Python 中的 `self` 关键字类似，可以理解为**指向对象本身的一个指针**。

假设有一个教师类 `Teacher` 的定义如下：

```java
public class Teacher {
    private String name;      // 教师名称
    private double salary;    // 工资
    private int age;          // 年龄
}
```

在上述代码中 `name`、`salary ` 和 `age` 的作用域是 `private`，因此在类外部无法对它们的值进行设置。为了解决这个问题，可以为 `Teacher` 类添加一个构造方法，然后在构造方法中传递参数进行修改。代码如下：

```java
// 创建构造方法，为上面的3个属性赋初始值
public Teacher(String name,double salary,int age) {
    this.name = name;      // 设置教师名称
    this.salary = salary;  // 设置教师工资
    this.age = age;        // 设置教师年龄
}
```

在 `Teacher` 类的构造方法中使用了 `this` 关键字对属性 `name`、`salary` 和 `age` 赋值，`this` 表示当前对象。`this.name = name` 语句表示一个赋值语句，等号左边的 `this.name` 是指当前对象具有的变量 `name`，等号右边的 `name` 表示参数传递过来的数值。

---

#### super 关键字

与 Python 类似，`super` 可以理解为**是指向自己超（父）类对象的一个指针**，而这个超类指的是离自己最近的一个父类。`super` 的用法与 `this` 类似，只不过是在子类中的变量或方法与父类中的同名时，用来访问父类的变量或方法。如下：

```java
class Country {
    String name;
    void value() {
       name = "China";
    }
}
  
class City extends Country {
    String name;
    void value() {
        name = "Shanghai";
        super.value(); // 访问父类的方法
        System.out.println(name);
        System.out.println(super.name); // 访问父类的属性
    }
  
    public static void main(String[] args) {
       City c=new City();
       c.value();
    }
}
```

---

#### 通过关键字引用构造函数

- `super(参数)`：调用父类中的某一个构造函数。
- `this(参数)`：调用本类中另一种形式的构造函数。
- 以上两条语句应该**放在构造函数的第一条语句的位置**，正因如此，两条语句不能同时出现。

```java
class Person { 
    public static void prt(String s) { 
       System.out.println(s); 
    } 
   
    Person() { 
       prt("父类·无参数构造方法： "+"A Person."); 
    }//构造方法(1) 
    
    Person(String name) { 
       prt("父类·含一个参数的构造方法： "+"A person's name is " + name); 
    }//构造方法(2) 
} 
    
public class Chinese extends Person { 
    Chinese() { 
       super(); // 调用父类构造方法（1） 
       prt("子类·调用父类无参数构造方法"： "+"A chinese coder."); 
    } 
    
    Chinese(String name) { 
       super(name);// 调用父类具有相同形参的构造方法（2） 
       prt("子类·调用父类含一个参数的构造方法"： "+"his name is " + name); 
    } 
    
    Chinese(String name, int age) { 
       this(name);// 调用具有相同形参的构造方法（3） 
       prt("子类：调用子类具有相同形参的构造方法：his age is " + age); 
    } 
    
    public static void main(String[] args) { 
       Chinese cn = new Chinese(); 
       cn = new Chinese("codersai"); 
       cn = new Chinese("codersai", 18); 
    } 
}
```

运行结果如下：

```
父类·无参数构造方法： A Person.
子类·调用父类无参数构造方法“： A chinese coder.
父类·含一个参数的构造方法： A person's name is codersai
子类·调用父类含一个参数的构造方法“： his name is codersai
父类·含一个参数的构造方法： A person's name is codersai
子类·调用父类含一个参数的构造方法“： his name is codersai
子类：调用子类具有相同形参的构造方法：his age is 18
```

由此可见，可以用 `super` 和 `this` 分别调用父类的构造方法和本类中其他形式的构造方法。 `Chinese` 类第三种构造方法调用的是本类中第二种构造方法，而第二种构造方法是调用父类的，因此要先调用父类的构造方法，再调用本类中第二种，最后重写第三种构造方法。



### 访问控制

同C++一样，Java中，也可以使用访问控制符来**保护对类、变量、方法和构造方法的访问**。Java 支持以下 4 种不同的访问权限：

| 修饰符    | 当前类 | 同一包内 | 子孙类(同一包) | 子孙类(不同包) | 其他包 |
| :-------- | :----- | :------- | :------------- | :------------- | :----- |
| public    | True   | True     | True           | True           | True   |
| protected | True   | True     | True           | 详见下文       | False  |
| default   | True   | True     | True           | False          | False  |
| private   | True   | False    | False          | False          | False  |

---

#### 默认访问修饰符 default

如果不写修饰符，则使用 `default` 作为修饰符，使用该访问修饰符声明的变量和方法，对同一个包内的类是可见的。**接口里的变量都隐式声明为 `public static final` ，而接口里的方法默认情况下访问权限为 `public` 。**

```java
String version = "1.5.1";
boolean processOrder() {return true;}
```

---

#### 私有访问修饰符 private

该修饰符**不能修饰类(外部类)**，而使用该访问修饰符声明的变量和方法、只能被所属类访问，并且类和接口不能声明为 `private` 。如果要在外部类访问，只能通过其类提供的公共的 `getter ` 方法被外部类访问，如下所示：

```java
public class Logger {
    
    private String format; // 私有静态变量
    
    public String getFormat() { // 公共getter方法，用于外部类访问
        return this.format;
    }
    
    public void setFormat(String format) { // 公共setter方法，用于外部类修改
        this.format = format;
    }
}
```

实例中，`Logger` 类中的 `format` 变量为私有变量，所以其他类不能直接得到和设置该变量的值。为了使其他类能够操作该变量，定义了两个公共方法：`getFormat()` 和 `setFormat(String format)` 。

---

#### 公有访问修饰符 public

被声明为 `public` 的类、方法、构造方法和接口能够被任何其他类访问。如果几个相互访问的 `public` 类分布在不同的包中，则需要导入相应类所在的包。由于类的继承性，类所有的公有方法和变量都能被其子类继承。

 ```java
public static void main(String[] arguments)
 ```

Java 程序的 `main()` 方法必须设置成公有的，否则解释器将不能运行该类。

---

#### 受保护访问修饰符 protected

`protected` 需要从以下两个点来分析说明：

- **子类与基类在同一包中**：被声明为 `protected` 的变量、方法和构造器能被同一个包中的任何其他类访问；
- **子类与基类不在同一包中**：那么在子类中，子类实例可以访问其从基类继承而来的 `protected` 方法，而不能访问基类实例的`protected` 方法。

`protected` 可以修饰数据成员，构造方法，方法成员，**不能修饰类（内部类除外）**。

接口及接口的成员变量和成员方法不能声明为 `protected` 。 可以看看下图演示：

![img](https://www.runoob.com/wp-content/uploads/2013/12/java-protected.gif)	

子类能访问 `protected` 修饰符声明的方法和变量，这样就能保护不相关的类使用这些方法和变量。

```java
// 下面的父类使用了protected访问修饰符，子类重写了父类的openSpeaker()方法
class AudioPlayer {
   protected boolean openSpeaker(Speaker sp) {
      // 实现细节
   }
}
 
class StreamingAudioPlayer extends AudioPlayer {
   protected boolean openSpeaker(Speaker sp) {
      // 实现细节
   }
}
```

---

#### 访问控制和继承

请注意以下方法继承的规则：

- 父类中声明为 `public` 的方法在子类中也必须为 `public` 。
- 父类中声明为 `protected` 的方法在子类中要么声明为 `protected`，要么声明为 `public`，不能声明为 `private` 。
- 父类中声明为 `private` 的方法，不能够被子类继承。



### static 关键字

在类中，使用 `static` 修饰符修饰的属性（成员变量）称为静态变量，也可以称为类变量，常量称为静态常量，方法称为静态方法或类方法，**它们统称为静态成员，归整个类所有，随类一起被加载，因此不依赖于类的特定实例，被类的所有实例共享**，就是说 `static` 修饰的方法或者变量不需要依赖于对象来进行访问，只要这个类被加载，Java 虚拟机就可以根据类名找到它们。

调用静态成员的语法形式如下：

```java
类名.静态成员 // 如 Math.sqrt()
```

**注意**：

- `static` 修饰的成员变量和方法，从属于类，因此也称类变量和类方法，而普通变量和方法则从属于对象。
- 静态变量只会加载一次，且存储在方法区的静态域中。
- 静态方法不能调用非静态成员，因为加载类时，非静态成员不会随类一起加载，所以编译会报错。
- `static` 还可以修饰**代码块**和**内部类**，这些之后再说。

---

#### 静态变量

类的成员变量可以分为以下两种：

1. 静态变量（或称为类变量），指被 `static` 修饰的成员变量。
2. 实例变量，指没有被 `static` 修饰的成员变量。


静态变量与实例变量的区别如下：

1. 静态变量

	- 运行时，Java 虚拟机只为静态变量分配一次内存，在加载类的过程中完成静态变量的内存分配。
	- 在类的内部，可以在任何方法内直接访问静态变量。
	- 在其他类中，可以通过类名访问该类中的静态变量。

2. 实例变量

	- 每创建一个实例，Java 虚拟机就会为实例变量分配一次内存。
	- 在类的内部，可以在非静态方法中直接访问实例变量。
	- 在本类的静态方法或其他类中则需要通过类的实例对象进行访问。


静态变量在类中的作用如下：

- 静态变量可以被类的所有实例共享，因此静态变量可以作为实例之间的共享数据，增加实例之间的交互性。
- 如果类的所有实例都包含一个相同的常量属性，则可以把这个属性定义为静态常量类型，从而节省内存空间。

```java
public static double PI = 3.14159256; // 例如，在类中定义一个静态常量 PI
```



如下是一个对静态变量的实例：

```java
// 创建一个带静态变量的类，然后在main()方法中访问该变量并输出结果
public class StaticVar {
    public static String str1 = "Hello";
    public static void main(String[] args) {
        String str2 = "World!";
        // 直接访问str1
        String accessVar1 = str1+str2;
        System.out.println("第 1 次访问静态变量，结果为："+accessVar1);
        // 通过类名访问str1
        String accessVar2 = StaticVar.str1+str2;
        System.out.println("第 2 次访问静态变量，结果为："+accessVar2);
        // 通过对象svt1访问str1
        StaticVar svt1 = new StaticVar();
        svt1.str1 = svt1.str1+str2; // 注意，此处类的静态变量str1已经被赋值为"HelloWorld!"，对所有实例生效
        String accessVar3 = svt1.str1;
        System.out.println("第3次访向静态变量，结果为："+accessVar3);
        // 通过对象svt2访问str1
        StaticVar svt2 = new StaticVar();
        String accessVar4 = svt2.str1+str2; // 因此，accessVar4 = "HelloWorld!" + "World!"
        System.out.println("第 4 次访问静态变量，结果为："+accessVar4);
    }
}
```

运行结果如下：

```
第 1 次访问静态变量，结果为：HelloWorld!
第 2 次访问静态变量，结果为：HelloWorld!
第 3 次访向静态变量，结果为：HelloWorld!
第 4 次访问静态变量，结果为：HelloWorld!World!
```

由此可见，在类中定义静态属性（成员变量），在 `main()` 方法中能直接访问，也能通过类名访问，还能通过类的实例对象来访问。

**注意：静态变量是被多个实例所共享的，就像运行结果的第四行输出一样。**

---

#### 静态方法

与成员变量类似，成员方法也可以分为以下两种：

1. 静态方法（或称为类方法），指被 `static` 修饰的成员方法。
2. 实例方法，指没有被 `static` 修饰的成员方法。


静态方法与实例方法的区别如下：

- 静态方法不需要通过它所属的类的任何实例就可以被调用，因此在静态方法中不能使用 `this` 关键字，也不能直接访问所属类的实例变量和实例方法，但是可以直接访问所属类的静态变量和静态方法。另外，和 `this` 关键字一样，`super` 关键字也与类的特定实例相关，所以在静态方法中也不能使用 `super` 关键字。

- 在实例方法中可以直接访问所属类的静态变量、静态方法、实例变量和实例方法。

    

如下是一个对静态方法的实例：

```java
// 创建一个带静态变量的类，添加几个静态方法对静态变量的值进行修改，然后在main()方法中调用静态方法并输出结果
public class StaticMethod {
    public static int count = 1;    // 定义静态变量count
    public int method1() {    
        // 实例方法method1
        count++;    // 访问静态变量count并赋值
        System.out.println("在静态方法 method1()中的 count="+count);    // 打印count
        return count;
    }
    public static int method2() {    
        // 静态方法method2
        count += count;    // 访问静态变量count并赋值
        System.out.println("在静态方法 method2()中的 count="+count);    // 打印count
        return count;
    }
    public static void PrintCount() {    
        // 静态方法PrintCount
        count += 2;
        System.out.println("在静态方法 PrintCount()中的 count="+count);    // 打印count
    }
    public static void main(String[] args) {
        StaticMethod sft = new StaticMethod();
        // 通过实例对象调用实例方法
        System.out.println("method1() 方法返回值 intro1="+sft.method1());
        // 直接调用静态方法
        System.out.println("method2() 方法返回值 intro1="+method2());
        // 通过类名调用静态方法，打印 count
        StaticMethod.PrintCount();
    }
}
```

运行结果如下：

```
在静态方法 method1()中的 count=2
method1() 方法返回值 intro1=2
在静态方法 method2()中的 count=4
method2() 方法返回值 intro1=4
在静态方法 PrintCount()中的 count=6
```

在该程序中，静态变量 `count` 作为实例之间的共享数据，因此在不同的方法中调用 `count`，值是不一样的。从该程序中可以看出，在静态方法 `method1()` 和 `PrintCount()` 中是不可以调用非静态方法 `method1()` 的，而在 `method1()` 方法中可以调用静态方法 `method2()` 和 `PrintCount()` 。

在访问非静态方法时，需要通过实例对象来访问，而在访问静态方法时，能直接访问，也能通过类名来访问，还能通过实例对象来访问。



### final 关键字

`final` 在 Java 中常用来表示**常量**，且应用于类、方法和变量时意义是不同的，但本质是一样的，都表示**不可改变**。

**注意事项：**

- `final` 修饰的变量的值不可以改变，此时该变量可以被称为常量
- `final` 修饰的方法不可以被重写
- `final` 修饰的类不可以被继承

---

#### 修饰变量

`final`修饰的变量即成为常量，只能赋值一次，但是所修饰局部变量和成员变量有所不同。

1. `final` 修饰的局部变量必须使用之前被赋值一次才能使用。
2. `final` 修饰的成员变量在声明时没有赋值的叫“空白 final 变量”。**空白 final 变量必须在构造方法或静态代码块中初始化。**

***注：`final` 修饰的变量不能被赋值这种说法是错误的，严格的说法是 `final` 修饰的变量不可被改变，一旦获得初始值，该变量就不能被重新赋值。***

```java
// 若是成员变量仅声明不赋值，则必须在构造方法或静态代码块中初始化
final int e; e = 100; // 只能赋值一次
final static int f = 200; // 常见用法，可加修饰符
```

当使用 `final` 修饰基本类型变量时，不能对基本类型变量重新赋值，因此基本类型变量不能被改变。 但对于引用类型变量而言，它保存的仅仅是一个引用，`final` 只保证这个引用类型变量所引用的地址不会改变，即一直引用同一个对象，但这个对象完全可以发生改变。

```java
final int[] iArr = {5, 6, 12, 9};
Arrays.sort(iArr); // 对数组元素进行排序，合法
iArr[2] = -8;      // 对数组元素赋值，合法
iArr = null;       // 对iArr重新赋值，非法

final Person person = new Person(45); // 构造器参数用来初始化年龄
person.age = 18; // 对属性进行操作，合法
person = null;   // 对person重新赋值，非法
```

***注：使用 final 声明的常量，一般要求全部的字母大写，如 SEX，这点在开发中是非常重要的。***

---

#### 修饰方法

`final` 修饰的方法不可被重写，如果出于某些原因，不希望子类重写父类的某个方法，则可以使用 `final` 修饰该方法。

如果子类中定义一个与父类 `private` 方法同名、同形参列表、同返回值类型的方法，也不是方法重写，**只是重新定义了一个新方法**。因此，即使使用 `final` 修饰一个 `private` 访问权限的方法，依然可以在其子类中“重写”该方法。

```java
public class PrivateFinalMethodTest {
    private final void test() {...}
}

class Sub extends PrivateFinalMethodTest {
    public void test() {...} // 没有问题，因为不算重写
}
```

---

#### 修饰类

`final` 修饰的类不能被继承。当子类继承父类时，将可以访问到父类内部数据，并可通过重写父类方法来改变父类方法的实现细节，这可能导致一些不安全的因素。为了保证某个类不可被继承，则可以使用 final 修饰这个类。

下面代码示范了 final 修饰的类不可被继承。

```java
final class SuperClass {...}
class SubClass extends SuperClass {...} // 编译出错
```

因为 `SuperClass` 类是一个 `final` 类，而 `SubClass` 试图继承 `SuperClass` 类，这将会引起编译错误。



### 可变长参数

Java 从 JDK1.5 以后，允许定义形参长度可变的参数，从而允许为方法指定数量不确定的形参。如果在定义方法时在最后一个形参类型后增加3个点即(...)，则表明该形参可以接受多个参数值，多个参数值会被当做**数组**传入。

```java
public class Test {
	public static void main(String[] args) {
		par("张", "陈", "刘");
	}

	public static void par(String... strings) { // 声明可变长参数，其实就是数组
		for (String s : strings) {
			System.out.print(s);
		}
	}
}
```

**注意事项：**

-  调用时，如果同时能匹配固定参数和可变长参数的方法，会优先匹配固定参数方法。

-  如果能同时和2个包含可变参数的方法想匹配，则编译会报错，因为编译器不知道该调用哪个方法。

-  一个方法只能有一个可变参数，且可变参数应为最后一个参数。



### 方法重载

类的特性之一，与C++一样，在Java中，你可以通过在一个类中定义多个**同名**的方法，且每个方法具有**不同的参数类型<u>或</u>参数个数**。这样一来在调用方法时通过传递给它们的不同个数和类型的参数，以及传入参数的顺序来就可以决定具体使用哪个方法。方法重载提高了程序的兼容性和可读性，使程序可以处理多种情况。

如下代码所示：

```java
public class TestMax {
    // 主方法
    public static void main(String[] args) {
        int i = 5;
        int j = 2;
        int k = max(i, j);
        System.out.println( i + " 和 " + j + " 比较，最大值是：" + k);
    }
 
    // 返回两个整数变量较大的值
    public static int max(int num1, int num2) {
        int result;
        if (num1 > num2)
           result = num1;
        else
           result = num2;
        return result; 
    }
    
    // max方法重载，使其可以处理浮点数
    public static double max(double num1, double num2) { // 同名且具有不同的参数类型
        if (num1 > num2)
            return num1;
        else
            return num2;
    }
}
```

***注：重载的方法必须拥有不同的参数列表，你不能仅仅依据修饰符或返回值类型的不同来重载方法。***



### 虚拟方法

Java **多态性**的体现之一，具体用法是将用**子类**创建的实例绑定到用**父类**声明的引用变量上，如下：

```java
Father name = new Son() // Father为父类，Son为子类，name为引用变量名；必须要有继承关系！
```

**虽然用的是子类的构造器创建，但 `name` 只能访问父类所拥有的属性和方法，且如果子类该方法有重写，则会访问子类重写后的方法**，看起来没啥用，实际上提高代码的兼容性，具体用法如下：

```java
public class Test {
    public static void main(String[] args) {
        action(new Fuck()); // 相当于 Animal animal = new Fuck()
        action(new Shit()); // 相当于 Animal animal = new Shit()
    }
    
    public static void action(Animal animal) {
        animal.shout(); // 这里调用的是子类重写的方法
    }
}

class Animal {
    public void shout() {
        System.out.println("叫~");
    }
}

class Fuck extends Animal {         // 继承
    public void shout() {           // 重写
        System.out.println("Fuck!");
    }
}

class Shit extends Animal {
    public void shout() {           // 同上
        System.out.println("Shit!");
    }
}
```

运行结果如下：

```
Fuck!
Shit!
```

如果没有虚拟方法，则需要对上面代码中的的 `action` 方法进行**重载**，分别修改参数类型为 `Fuck`，`Shit` 才能使用，那样过于冗杂。



### 代码块

在 Java 中，使用 `{}` 括起来的代码被称为**代码块**（Code block），根据其**位置**和**声明**的不同，可以分为：

- 局部代码块：常在方法中出现，可以限定变量生命周期，及早释放，提高内存利用率
- 构造代码块：在类中方法外出现的局部代码块，每次调用构造方法都会执行，并且在构造方法前执行
- 同步代码块：指被 `Synchronized` 修饰的代码块，这是一种线程同步机制，被该关键词修饰的代码块会被加上内置锁
- 静态代码块：在类中方法外出现，并加上 `static` 修饰，常用于给类进行初始化，在加载的时候就执行，且静态代码块只执行一次

---

同步代码块属于多线程部分，此处先不展示，其余代码块示例如下：

```java
class StatisCodeBlock {
    static { // 静态代码块，在方法外出现
        int number1 = 10;
        System.out.println("1、静态代码块变量： " + number1);
    }

    { // 构造代码块，在方法外出现
        int number2 = 20;
        System.out.println("2、构造代码块变量： " + number2);
    }

    public StatisCodeBlock() { // 构造方法
        { // 局部代码块
            int number5 = 50; // 局部中的局部变量，生命周期仅限代码块中
            System.out.println("5、局部代码块变量： " + number5);
        }
        System.out.println("这是构造方法 StatisCodeBlock()");
    }

    static { // 静态代码块按照声明先后顺序执行
        int number3 = 30;
        System.out.println("3、静态代码块变量： " + number3);
    }

    { // 构造代码块也按照声明先后顺序执行，且构造代码块先于构造方法执行
        int number4 = 40;
        System.out.println("4、构造代码块变量： " + number4);
    }
}

public class CodeBlockTest {
    public static void main(String[] args) {
        StatisCodeBlock codeBlock = new StatisCodeBlock(); // 创建对象
        System.out.println("======第二次创建实例======"); // 注意：构造代码块通过构造方法自动调用
        StatisCodeBlock codeBlock2 = new StatisCodeBlock();
    }
}
```
运行结果如下：

```
1、静态代码块变量： 10
3、静态代码块变量： 20
2、构造代码块变量： 30
4、构造代码块变量： 40
5、局部代码块变量： 50
这是构造方法 StatisCodeBlock()
======第二次创建实例======
2、构造代码块变量： 20
4、构造代码块变量： 40
5、局部代码块变量： 50
这是构造方法 StatisCodeBlock()
```



### 包装类

......



### 内部类

Java 一个类中可以嵌套另外一个类，叫做内部类，**它享有作为一个类所拥有的大部分功能**，语法格式如下：

```java
class OuterClass {   // 外部类
    class NestedClass {...}// 嵌套类，或称为内部类
}
```

---

#### 成员内部类

成员内部类是定义在方法外的内部类，作为外部类的成员，**它同时还享有作为一个成员所拥有的大部分功能**

成员内部类可以使用修饰符，这决定了**成员内部类和外部类相互之间的访问权限**以及**需不需要创建外部类来访问成员内部类**。

```java
class OuterClass {
    int x = 10; // 外部实例变量
    class InnerClass1 {int y = 1;} // 公有内部类
    private class InnerClass2 {int y = 2;} // 私有内部类
    static class InnerClass3 {int y = 3;} // 静态内部类
}

public class MyMainClass {
    public static void main(String[] args) {
        OuterClass myOuter = new OuterClass(); // 必须先实例化外部类，才能访问非静态内部类
        OuterClass.InnerClass1 myInner1 = myOuter.new InnerClass1();
        System.out.println(myInner1.y + myOuter.x); // 输出结果为：15
     // OuterClass.InnerClass2 myInner2 = myOuter.new InnerClass2(); 编译报错，因为外部类无法访问私有内部类
        OuterClass.InnerClass3 myInner3 = new OuterClass.InnerClass3(); // 无需创建外部类，可以直接访问静态内部类
        System.out.println(myInner3.y); // 输出结果为：3 
    }
}
```

*注：静态内部类无法访问外部类的成员，因为外部类还没加载*

---

#### 局部内部类

局部内部类是定义在方法内，代码块内，构造器内的内部类，比较少见，下面是一个比较常见的用法：

```java
// 返回一个是实现Test接口的类的对象
public Test getTest() {
    class MyTest implements Test {...} // 创建一个实现Test接口的类：局部内部类
    return new MyTest(); // 返回使用虚拟方法 Test ? = new MyTest()
}
```

**注意事项：**

- 局部内部类不能使用访问控制修饰符和 `static` 关键字修饰，也不能定义 `static` 成员
- 局部内部类只在当前方法中有效
- 局部内部类中还可以包含内部类，不过这些类也不能用一样的修饰符
- 局部内部类中可以访问外部类的所有成员
- 局部内部类中只可以访问当前方法中 `final` 类型的参数与变量



### 抽象类

在面向对象的概念中，所有的对象都是通过类来描绘的，但是反过来，并不是所有的类都是用来描绘对象的，如果一个类中**没有包含足够的信息来描绘一个具体的对象**，这样的类就是抽象类。

在 Java 语言中使用 `abstract` 关键字来定义抽象类和方法。如下：

```java
public abstract class Test {          // 抽象类
    public abstract void fuck(int x); // 抽象方法，没有方法体，由继承的子类来重写实现
    public void shit(int x) {...}     // 非抽象方法
}
```
**要点：**

- 抽象类除了**不能实例化对象**之外，**类的其它功能依然存在**，成员变量、成员方法和**构造方法**的访问方式和普通类一样

- 由于抽象类不能实例化对象，所以抽象类**必须被继承**，才能被使用

- 含有抽象方法的一定是抽象类，反之则不一定

- 若抽象类含有抽象方法，则继承的子类**必须重写从父类及更高辈分的类继承下来的抽象方法**，除非子类也是抽象类
- 属性、代码块、构造方法、`private` 方法、`static` 方法、`final` 方法和类，不能声明为抽象



### 接口

接口在 Java 中是一个抽象类型，**并不是类**，是抽象方法的集合，接口通常以 `interface` 关键字来声明。一个类通过继承接口的方式，从而来继承接口的抽象方法，除非实现接口的类是抽象类，否则该类要定义接口中的所有方法。

```java
[public] interface Name [extends ...] { // 接口可以加其他修饰符，且支持多继承，不必使用abstract关键字
    [public static final] int x = 1; // 全局常量
    [public abstract] void setName(String name); // 抽象方法,没有方法体
}
```

**要点：**

- 接口不能实例化且只有**公有的抽象方法**，必须被继承实现。继承接口的类必须实现接口内所有抽象方法，否则就必须声明为抽象类
- 接口中，除默认方法和静态方法，其余方法会被隐式的指定为 `public abstract` ，除 `private` 其他修饰符都会报错
- 接口中的变量会被隐式的指定为 `public static final` ，其他修饰符都会报错
- 接口不能包含成员变量，除了 `static` 和 `final` 变量
- Java 8 之后可以使用 `default` 关键字在接口中修饰非抽象方法

---

#### 接口的实现和继承

接口的实现，继承，方法实现与抽象类类似，可以参考**新特性**部分的代码，这里不再赘述，只提几点注意事项：

- 类在实现接口的方法时，不能抛出强制性异常，只能在接口中，或者继承接口的抽象类中抛出该强制性异常。
- 类在重写方法时要保持一致的方法名，并且应该保持相同或者相兼容的返回值类型。
- 如果实现接口的类是抽象类，那么就没必要实现该接口的方法。
- 接口可以多继承

---

#### 新特性

> **注**：JDK 1.8 以后，接口里可以有**静态方法**和**方法体**
> **注**：JDK 1.8 以后，接口允许包含具体实现的方法，该方法称为"默认方法"，使用 `default` 关键字修饰。可参考 [Java 8 默认方法](https://www.runoob.com/java/java8-default-methods.html)
> **注**：JDK 1.9 以后，允许将方法定义为 `private`，使某些复用的代码不会把方法暴露出去。可参考 [Java 9 私有接口方法](https://www.runoob.com/java/java9-private-interface-methods.html)

示例如下：

```java
public interface Test {
    int x = 1; // 全局常量
    public void method1(); // 抽象方法
    public static void method2() { // 静态方法，只能通过 Test.method2 来调用
        System.out.print("Hello");
    }
    public default void method3() { // 默认方法
        System.out.print("World");
    }
}
public class Main implements Test {
    public void method1() { // 实现抽象方法
        Test.method2(); // 调用接口的静态方法
    }
    public void method3() { // 重写默认方法
        Test.super.method3(); // 重写的前提下，调用接口的默认方法
    }
}
```

**注意事项：**

- 接口中的静态方法只能通过接口来调用，实现类无法访问
- 接口中的默认方法可以通过实现类的对象来调用，若该方法被重写，则调用的是重写后的方法
- 如果子类(或实现类)继承的父类和实现的接口中声明了同名同参数的默认方法，那么子类在没有重写此方法的情况下，默认调用的是**父类**中的同名同参数的方法*（类优先原则）*
- 如果实现类实现了多个接口，而这多个接口中定义了同名同参数的默认方法，那么在实现类没有重写此方法的情况下，编译器将会报错，所以只能通过方法重写解决*（接口冲突）*
- 如果想在已经重写的情况下，调用接口的默认方法，可以使用 `接口名.super.方法名` 来调用



## 十一、值传递和引用传递

**值传递**：在调用函数时，将实际参数复制一份传递到函数中，这样在函数中对参数进行修改，就不会影响到原来的实际参数；

**引用传递**：在调用函数时，将实际参数的地址直接传递到函数中。这样在函数中对参数进行的修改，就会影响到实际参数

```java
public class Test {
    public int var = 10; // 实例变量
    public static void main(String[] args) {
        int a = 10;
        int[] b = {10, 0};
        Test c = new Test();
        System.out.println("传递前：" + a);
        System.out.println("传递前：" + b[0]);
        System.out.println("传递前：" + c.var);
        modify(a); modify(b); modify(c); // 传递参数
        System.out.print("—————————");
        System.out.println("传递后：" + a);
        System.out.println("传递后：" + b[0]);
        System.out.println("传递后：" + c.var);
    }
 
    public static void modify(int x) {
        x = 20; // 修改基本数据类型
    }
    // 以下修改引用数据类型
    public static void modify(int[] x) { // 方法重载一
        x[0] = 20; // 修改数组元素
    }
    public static void modify(Test x) { // 方法重载二
        x.var = 20; // 修改实例变量
    }
}
```

运行结果如下：

```
传递前：10
传递前：10
传递前：10
—————————
传递后：10
传递后：20
传递后：20
```

**注意：Java 中只有值传递，引用传递实质上也是值传递，因为它传的是地址，类似于指针。**



## 十二、异常处理

Java 中的所有异常都被封装成一个类且都继承于 Exception 类，而它是 Throwable 类的子类。除了Exception类外，Throwable还有一个子类 Error，但 Java 程序通常不捕获错误，它们一般在 Java 程序处理的范畴之外，所以只是用来指示运行时环境发生的错误。

![tree](https://www.runoob.com/wp-content/uploads/2013/12/exception-hierarchy.png)

要理解 Java 异常处理是如何工作的，你需要掌握以下三种类型的异常：

- **检查性异常：**最具代表的检查性异常是用户错误或问题引起的异常，这是程序员无法预见的。例如要打开一个不存在文件时，一个异常就发生了，这些异常在编译时不能被简单地忽略。
- **运行时异常：** 运行时异常是可能被程序员避免的异常。与检查性异常相反，运行时异常可以在编译时被忽略。
- **错误：** 错误不是异常，而是脱离程序员控制的问题。错误在代码中通常被忽略。例如，当栈溢出时，一个错误就发生了，它们在编译也检查不到的。



### 捕获异常

---

#### 基本操作

Java 中使用 `try` 和 `catch` 关键字可以捕获异常。`try-catch` 代码块被放在异常可能发生的地方。

```java
// 下面的例子中声明有两个元素的一个数组，当代码试图访问数组的第四个元素的时候就会抛出一个异常
import java.io.*;
public class ExcepTest {
    public static void main(String args[]){
        try {
            int a[] = new int[2];
            System.out.println("Access element three :" + a[3]);
        } catch(ArrayIndexOutOfBoundsException e) { // 声明捕获数组下标越界异常类的引用变量e作为形参
            System.out.println("Exception thrown  :" + e); // 此处e则表示ArrayIndexOutOfBoundsException类的实例
        }
        System.out.println("Out of the block");
    }
}
```

`catch` 语句包含要捕获异常类型的声明。当保护代码块中发生一个异常时，`try` 后面的 `catch` 块就会被检查，如果发生的异常**包含**在 `catch` 块中，异常会被传递到该 `catch` 块的形参 `e` 中，这和传递一个参数到方法是一样。

---

#### 多重捕获块

一个 `try` 代码块后面跟随多个 `catch` 代码块的情况就叫多重捕获。

多重捕获块的语法如下所示：

```java
// 下面的代码段包含了 2 个 catch 块，可以在 try 语句后面添加任意数量的 catch 块
try {
    file = new FileInputStream(fileName);
    x = (byte) file.read();
} catch(FileNotFoundException f) { // 不匹配，跳过
    f.printStackTrace();
    return -1;
} catch(IOException i) { // 匹配，被捕获，执行代码块
    i.printStackTrace();
    return -1;
}
```

如果保护代码中发生异常，异常会按照先后顺序一层一层的匹配 `catch` 块中的异常，直到异常被捕获或者通过所有的 `catch` 块。

为了避免异常通过所有的 `catch` 块，我们一般会将异常类按辈分从小到大的顺序自上而下来声明 `catch` 块，如下所示：

```java
try{
    // Code
} catch(FileNotFoundException e) { // 最小
    // Code
} catch(IOException e) { // 中间
    // Code
} catch(Exception e) { // 所有异常的父类，绝对漏不掉
    // Code
}
```

---

#### finally 关键字

`finally` 关键字用来创建在 `try` 代码块后面执行的代码块。无论是否发生异常，`finally` 代码块中的代码总会被执行，所以常用来运行清理类型等收尾善后性质的语句。

```java
public class ExcepTest {
    public static void main(String args[]) {
        int a[] = new int[2];
        try {
            System.out.println("Access element three :" + a[3]);
        } catch(ArrayIndexOutOfBoundsException e) { // 捕获异常，执行代码块
            System.out.println("Exception thrown  :" + e);
        } finally { // 无论有没有异常，都会执行代码块
            a[0] = 6;
            System.out.println("First element value: " +a[0]);
            System.out.println("The finally statement is executed");
        }
    }
}
```

运行结果如下：

```
Exception thrown  :java.lang.ArrayIndexOutOfBoundsException: 3
First element value: 6
The finally statement is executed
```

**注意事项：**

- `catch` 不能独立于 `try` 存在
- `try` 代码后不能既没 `catch` 块也没 `finally` 块
- `try`, `catch`, `finally` 块之间不能添加任何代码



### 抛出异常

如果一个方法没有捕获到一个检查性异常，那么该方法必须使用 `throws` 关键字来声明。`throws` 关键字放在方法签名的尾部。

无论是新实例化的还是刚捕获到的，也可以使用 `throw` 关键字抛出一个异常，将其交给调用者去处理。

```java
import java.io.*;
public class className { // 一个方法可以声明抛出多个异常，多个异常之间用逗号隔开
    public void withdraw(double amount) throws RemoteException,InsufficientFundsException {
        // Method implementation
        throw new RemoteException("Error"); // 手动抛出异常，注意用的是throw关键字
    }
    // Remainder of class definition
}
```

**注意事项：**

- 子类重写的方法抛出的异常类型**不大于**父类被重写的方法抛出的异常类型
- 当方法体内部的异常符合声明抛出的异常，则会被抛出，异常后续代码不被执行
- `throws` 的方式只是将异常抛给了方法的调用者。并没有真正将异常处理掉
- 手动抛出的异常是由自己手动生成并抛出的，并非系统运行生成的



### 自定义异常

在 Java 中你可以自定义异常。编写自己的异常类时需要记住下面的几点。

- 必须继承现有的异常结构，如 Exception、RuntimeException 等
- 可以提供全局常量：serialVersionUID，用来作为该异常的标识
- 提供重载的构造器
- 如果希望写一个**检查性异常**类，则需要继承 Exception 类。
- 如果你想写一个**运行时异常**类，那么需要继承 RuntimeException 类。

可以像下面这样定义自己的异常类：

```java
pub1ic class MyException extends RuntimeException {
    
    static final long serialVersionUID = -7034897193246939L; // 标识符，可选
    
    public MyException(){} // 空参构造器
    public MyException(String msg) { // 直接调用父类现成的有参构造器
    	super(msg);
    }
}
```



## 十三、多线程

Java 给多线程编程提供了内置的支持。 一条线程指的是进程中一个单一顺序的控制流，一个进程中可以并发多个线程，每条线程并行执行不同的任务。多线程是多任务的一种特别的形式，但多线程使用了更小的资源开销。

普通的 Java 程序至少有三个线程：主线程、垃圾收集线程、异常处理线程



### 线程的生命周期

线程是一个动态执行的过程，它也有一个从产生到死亡的过程。如图所示：

![img](https://www.runoob.com/wp-content/uploads/2014/01/java-thread.jpg)

- **新建状态:**

    创建一个线程对象后，该线程对象就处于新建状态。它保持这个状态直到程序启动这个线程。

- **就绪状态:**

    当该线程启动之后，该线程就进入就绪状态。就绪状态的线程处于就绪队列中，要等待 JVM 里线程调度器的调度。

- **运行状态:**

    如果就绪状态的线程获取 CPU 资源，就可以运行，此时线程便处于运行状态。处于运行状态的线程最为复杂，它可以变为阻塞状态、就绪状态和死亡状态。

- **阻塞状态:**

    如果一个线程执行了 **sleep**（睡眠）、**suspend**（挂起）等方法，失去所占用资源之后，该线程就从运行状态进入阻塞状态。在睡眠时间已到或获得设备资源后可以重新进入就绪状态。可以分为三种：

    - 等待阻塞：运行状态中的线程执行 `wait()` 方法，使线程进入到等待阻塞状态。
    - 同步阻塞：线程在获取 `synchronized` 同步锁失败(因为同步锁被其他线程占用)。
    - 其他阻塞：通过调用线程的 `sleep()` 或 `join()` 发出了 I/O 请求时，线程就会进入到阻塞状态。当 `sleep()` 状态超时，`join()` 等待线程终止或超时，或者 I/O 处理完毕，线程重新转入就绪状态。

- **死亡状态:**

    一个运行状态的线程完成任务或者其他终止条件发生时，该线程就切换到死亡状态。



### 创建线程

---

#### 继承 Thread 类

Java 提供了一个 Thread 类来处理线程，我们可以用以下方式创建一个线程：

```java
public class MyThread extends Thread { // 第一种方式：必须继承Thread类，受限于单继承性
    @Override
    public void run() {
        // 这里写你要运行的代码
    }
}
public static void main(String[] args) {
    MyThread t1 = new MyThread();
    t1.start(); // 使用start()方法，而不是直接调用run()方法
    // 下面是使用匿名方式创建线程
    new MyThread() {
        @Override
        public void run() {...}
    }.start()；
}
```

---

#### 实现 Runnable 接口

然鹅，开发中优先使用下面的方式创建线程：

```java
class MyThread implements Runnable { // 第二种方式：实现Runnable接口
    @Override
    public void run() { // 只用实现这一个方法
        // 这里写你要运行的代码
        System.out.println(Thread.currentThread().getName()) // 不能用this关键字或直接调用，只能静态调用
    }
}

public class ThreadTest1 {
    public static void main(String[] args) {
        MyThread sample = new MyThread()；
        Thread t1 = new Thread(sample); // 将实现类的对象作为Thread构造器的参数
        t1.start();
        Thread t2 = new Thread(sample);
        t2.start();
    }
}
```

第二种方式适用于多线程共用一个数据的情况*（实例变量）*；若用第一种数据，则需要将共用数据声明为静态*（类变量）*

---

#### 实现 Callable 接口

在 JDK 5.0 中新增了通过实现 `Callable` 接口来创建线程的方式，如下：

```java
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;
 // 因为Callable是一个原始类型。对泛型类型Callable<V>的引用应该参数化，所以这里我们使用<Integer>指明类型
public class MyThread implements Callable<Integer> { // 第三种方式：实现Callable接口
    public static void main(String[] args) {
        MyThread ctt = new MyThread(); // 创建实例
        FutureTask<Integer> ft = new FutureTask<Integer>(ctt); // 使用FutureTask类来包装Callable对象
        for (int i = 0; i < 100; i++) {
            System.out.println(Thread.currentThread().getName() + " 的循环变量i的值" + i);
            if (i == 20) {
                new Thread(ft, "有返回值的线程").start(); // 使用FutureTask对象作为参数创建且命名并启动新线程
            }
        }
        try {
            System.out.println("子线程的返回值：" + ft.get()); // 调用FutureTask对象的get()方法来获得子线程的返回值
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }
    }
    @Override
    public Integer call() throws Exception { // 实现call()方法，以下为线程执行体
        int i;
        for (i = 0; i < 100; i++) {
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
        return i;
    }
}
```

---

#### 使用线程池

在 JDK 5.0 中新增了线程池，它可以**提前创建好线程存放在池中，使用时直接获取，用完放回池中**，优点如下：

- 提高响应速度（减少了创建新线程的时间）
- 降低资源消耗（重复利用线程池中线程，不需要每次都创建和销毁）
- 线程池提供了一些方法便于管理线程

```java
import java.util.concurrrrent.Executors;

class NumberThread implements Runnable {
    @Override
    public void run() {
        // 这里写你要运行的代码
    }
}

public class ThreadPoll {
    public static void main(String[] args) {
        ExecutorService service = Executors.newFixedThreadPool(10);
     // ThreadPoolExecutor control = (ThreadPoolExecutor) service;
     // control.setCorePoolSize(...) 设置核心池的大小
     // control.setKeepAliveTime(...) 设置线程闲置存活时间
        service.execute(new NumberThread()); // 加入并运行线程，不用手动start()，适用于Runnable
     // service.submit(); 适用于Callable
        service.shutdown(); // 关闭线程池
    }
}
```

线程池常用于开发，目前不要求掌握，仅了解即可

---

**注意事项：**

- 第三种方式虽功能强大，但较复杂，如果没有对返回值的要求，则一般使用前两种方式
- 通过 Thread 和 Runnable 创建的线程，须用重写的方式将该线程的操作写在 `run()` 方法里，用 Callable 创建则是在 `call()` 中
- 通过实现接口创建的线程类**只能以静态方式调用线程的常用方法**
- 启动线程使用 `start()` 方法，而不是直接调用 `run()` 方法，使用线程池则用 `execute()` 方法
- 除非用线程池，否则**不能调用已经调用过 `start()` 的线程**，就是说同一线程实例不能调用两次
- 第一种方式创建的多个线程共用一个 **MyThread 类**，而第二、三种方式则是共用一个 **MyThread 对象**



### 一些常用方法

- **start()**：启动线程，并执行对象的 `run()` 方法
- **run()**：线程在被调度时执行的操作
- **getName()**：返回线程的名称
- **setName(String name)**：设置该线程名称
- **Thread.currentThread()**：返回当前线程。在 Thread 子类中就是 `this`，通常用于主线程和 Runnable 实现类
- **yield()**： 线程让步
    - 暂停当前正在执行的线程，把执行机会让给优先级相同或更高的线程
    - 若队列中没有同优先级的线程，忽略此方法
- **join()**：当某个程序执行流中调用其他线程的 `join()` 方法时，调用线程将被阻塞，直到 `join()` 方法加入的 join 线程执行完为止
    - 低优先级的线程也可以获得执行
- **sleep(long millis)**： (毫秒级)
	- 令当前活动线程在指定时间段内放弃对CPU控制，使其他线程有机会被执行，时间到后重排队，**但不会释放锁**
	- 会抛出 `InterruptedException` 异常
- **wait()**：让进程进入阻塞状态**并释放锁**，**在同步结构中使用**且调用者必须是**同步监视器**，`notify() & notifyAll()` 也是如此
- **notify()**：随机唤醒一个在此对象监视器上等待的线程，常与 `wait()` 配合使用
    - **notifyAll()**：唤醒所有在此对象监视器上等待的线程
- **stop()**：强制线程生命期结束，**已经过时**，不推荐使用
- **isAlive()**：判断线程是否还活着

```java
class MyThread extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            if (i % 2 == 0) {
                try {
                    sleep(10); // 让线程暂停10ms，也就是进入阻塞状态
                } catch (InterruptedException e) { // 该方法会抛出异常，必须准备捕获
                    e.printStackTrace();
                }
                System.out.println(getName() + ":" + i);
            } // Java14 加入了yield关键字，所以必须通过类调用
            if (i % 20 == 0) {Thread.yield();} // 提前释放占用的CPU资源，重新接受调度（也有可能还是分配到该线程，与优先级有关）
        }
    }
    public MyThread(String name) {super(name);} // 这是用构造器命名，也可以用setName()
}

public class Test {
    public static void main(String[] args) {
        MyThread t1 = new MyThread("线程一"); // 构造器命名
        t1.start();
        Thread.currentThread().setName("主线程"); // 给主线程命名
    	for (int i = 0; i < 100; i++) {
            if (i % 2 == 0) {
                System.out.println(Thread.currentThread().getName() + ":" + i);
            }
            if (i == 0) {
                try {
                    t1.join(); // 让t1先运行，等t1运行完后在运行调用该方法的线程
                } catch (InterruptedException e) { // 同上
                    e.printStackTrace();
                }
            }
        }
        System.out.println(t1.isAlive());
    }
}
```

线程的运行具有不确定性，所以运行结果可能有所不同，故不展示。



### 线程的优先级

Thread 类中，优先级使用 1 ~ 10 的整数表示：

- 最低优先级 1：`Thread.MIN_PRIORITY`
- 最高优先级 10：`Thread.MAX_PRIORITY`
- 普通优先级 5：`Thread.NORM_PRIORITY`

我们可以使用下面两个方法来设置线程的优先级：

- **getPriority()**：获取线程的优先级
- **setPriority()**：设置线程的优先级

```java
public static void main(String[] args) { // 以下均为设置主线程的优先级
    Thread.currentThread().setPriority(Thread.MIN_PRIORITY);
    System.out.println(Thread.currentThread().getPriority()); // 1
    Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
    System.out.println(Thread.currentThread().getPriority()); // 10
    Thread.currentThread().setPriority(8); // 1 ~ 10
    System.out.println(Thread.currentThread().getPriority()); // 8
}
```

**注意：**高优先级的线程要抢占低优先级线程 CPU 的执行权。但是只是从概率上讲，高优先级的线程高概率的情况下被执行。并不意味着只有当高优先级的线程执行完以后，低优先级的线程才执行。



### 线程的同步

使用多线程的一大隐患就是安全问题，概括地说就是，**多个线程“同时”访问一个数据**。为了解决该问题，我们需要使用**同步机制**。

---

#### 同步代码块

用 `synchronized` 关键字修饰的代码块，就叫同步代码块，它会被加上**内置锁**，使得多线程无法同时执行该代码块内的代码

```java
// 以第二种方式展示
class MyThread implements Runnable {
    // Object obj = new Object(); // 该类为实例属性，用第二种方式创建线程可以满足共用同一把锁
    
    @Override
    public void run() {
     // synchronized(this) 通常这样用更方便
        synchronized(obj) { // 括号内为同步监视器，俗称：锁
            // 操作共享数据的代码
        }
    }
}
// 以第一种方式展示
public class MyThread extends Thread {
    // private static Object obj = new Object(); // 该类为类属性，用第一种方式创建线程可以满足共用同一把锁
    
    @Override
    public void run() {
     // synchronized(MyThread.class) 通常这样用更方便
        synchronized(obj) {
            // 操作共享数据的代码
        }
    }
}
```

**注意事项：**

- 任何一个类的实例对象都能充当锁，但要求多个线程共用同一把锁，即同一对象
- 使用同步机制即是把多线程的过程限制为单线程的过程，效率会降低
- 因为方式二共用一个的对象，所以更简便的方法是用**当前对象**充当锁，也就是 `this` ；**方式一不适用**
- 因为**类也算对象** *(Class 类的实例 )*，所以方式一也可以用 `MyThread.class` 充当锁，**方式二也适用**

---

#### 同步方法

如果操作共享数据的代码**完整地存在于一个方法中**，我们就可以将其声明为同步方法，如下：

```java
// 同步方法不一定要run()，也可以自己定义
class MyThread implements Runnable { // 实现
    @Override
    public synchronized void run() { // 同步监视器默认为：this
        // 操纵共享数据的代码
    }
}
class MyThread extends Thread { // 继承
    @Override
    public static synchronized void run() { // 要声明为静态！同步监视器默认为：MyThread.class
        // 操纵共享数据的代码
    }
}
```

**注意：**确保**操纵共享数据的代码被完整地包含在同步方法里**，不能多，也不能少，**同步代码块也一样**

---

#### Lock 锁

在 JDK 5.0 中新增了一种解决线程安全的措施：Lock 锁。它可以得到和 `synchronized` 一样的效果，但不同的是，Lock 锁可**手动获取锁和释放锁、可中断的获取锁、超时获取锁。**

Lock 是一个**接口**，两个直接实现类：ReentrantLock（重入锁）, ReentrantReadWriteLock（读写锁）。

示例如下：

```java
import java.util.concurrent.locks.ReentrantLock;
 
public class MyLockStudy implements Runnable {

    private int count;
    ReentrantLock l = new ReentrantLock(); // 可传入参数fair，用来确保按先后顺序执行线程，
 
    @Override
    public void run() {
        l.lock(); // 手动开启锁
        for (int i = 0; i < 2; i++) {
            System.out.println(Thread.currentThread().getName() + ": ");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        l.unlock(); // 手动解锁
    }
 
    public static void main(String args[]) {
        MyLockStudy runn = new MyLockStudy();
        Thread thread1 = new Thread(runn, "thread1");
        Thread thread2 = new Thread(runn, "thread2");
        Thread thread3 = new Thread(runn, "thread3");
        thread1.start();
        thread2.start();
        thread3.start();
    }
}
```

运行结果如下：

```
thread1:
thread1:
thread2:
thread2:
thread3:
thread3:
```



### 死锁

死锁是这样一种情形：多个线程同时被阻塞，它们中的一个或者全部都在等待某个资源被释放。由于线程被无限期地阻塞，因此程序不可能正常终止。

java 死锁产生的四个必要条件：

- **互斥使用**，即当资源被一个线程使用(占有)时，别的线程不能使用
- **不可抢占**，资源请求者不能强制从资源占有者手中夺取资源，资源只能由资源占有者主动释放。
- **请求和保持**，即当资源请求者在请求其他的资源的同时保持对原有资源的占有。
- **循环等待**，即存在一个等待队列：P1占有P2的资源，P2占有P3的资源，P3占有P1的资源。这样就形成了一个等待环路。

当上述四个条件都成立的时候，便形成死锁。当然，死锁的情况下如果打破上述任何一个条件，便可让死锁消失。

解决死锁问题的方法是：一种是用 synchronized，一种是用 Lock 显式锁实现。

而如果不恰当的使用了锁，且出现同时要锁多个对象时，会出现死锁情况，如下：

```java
import java.util.Date;

public class Test {
    public static String obj1 = "obj1";
    public static String obj2 = "obj2";

    public static void main(String[] args) {
        LockA la = new LockA();
        new Thread(la).start();
        LockB lb = new LockB();
        new Thread(lb).start();
    }
}

class LockA implements Runnable {
    public void run() {
        try {
            System.out.println(new Date().toString() + " LockA 开始执行");
            while (true) {
                synchronized (Test.obj1) {
                    System.out.println(new Date().toString() + " LockA 锁住 obj1");
                    Thread.sleep(3000); // 此处等待是给B能锁住机会
                    synchronized (Test.obj2) {
                        System.out.println(new Date().toString() + " LockA 锁住 obj2"); // 多半不会执行，因为死锁
                        Thread.sleep(60 * 1000); // 为测试，占用了就不放
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class LockB implements Runnable {
    public void run() {
        try {
            System.out.println(new Date().toString() + " LockB 开始执行");
            while (true) {
                synchronized (Test.obj2) {
                    System.out.println(new Date().toString() + " LockB 锁住 obj2");
                    Thread.sleep(3000); // 此处等待是给A能锁住机会
                    synchronized (Test.obj1) {
                        System.out.println(new Date().toString() + " LockB 锁住 obj1");
                        Thread.sleep(60 * 1000); // 为测试，占用了就不放
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

运行结果如下：

```
Tue May 05 10:51:06 CST 2015 LockB 开始执行
Tue May 05 10:51:06 CST 2015 LockA 开始执行
Tue May 05 10:51:06 CST 2015 LockB 锁住 obj2
Tue May 05 10:51:06 CST 2015 LockA 锁住 obj1
```

此时死锁产生，这里给出几点建议：

- 用专门的算法避开死锁
- 少定义同步资源
- 避免嵌套同步



## 十四、常用类

此处总结一些目前正在使用的常用类



### java.time

这是 JDK 8 新增的处理**时间**的 API ，使用前需要导入，对于之前版本的时间处理方式，我们不多赘述。

---

#### 创建时间对象

`java.time` 提供了两种实例化方式以及一些常用方法，如下：

```java
import java.time.*;

public class Test {
    public static void main(String[] args) {
        // now(): 创建当前时间和日期的实例对象
        LocalDate localDate = LocalDate.now();
        LocalTime localTime = LocalTime.now();
        LocalDateTime localDateTime = LocalDateTime.now();
        System.out.println(localDate); // 2023-01-26
        System.out.println(localTime); // 14:23:25.428286700
        System.out.println(localDateTime); // 2023-01-26T14:23:25.428286700
        
        // of(): 创建指定时间和日期的实例对象
        LocalDateTime localDateTime1 = LocalDateTime.of(2003, 12, 18, 12, 00, 00);
        System.out.println(localDateTime1); // 2003-12-18T12:00
        
        // getXXX(): 获取时间点
        System.out.println(localDateTime.getDayOfMonth()); // 26 - 该月第几天
        System.out.println(localDateTime.getDayOfWeek());  // THURSDAY - 该周第几天
        System.out.println(localDateTime.getMonth());      // JANUARY - 当前月份
        System.out.println(localDateTime.getMonthValue()); // 1 - 当前月份的值
        System.out.println(localDateTime.getMinute());     // 23 - 当前分钟
        
        // withXXX(): 获取指定时间点，返回一个指定LocalDate对象
        LocalDate localDate1 = localDate.withDay0fMonth(22); // 指定该月第22天，原对象属性不变
        System.out.println(localDate1); // 2023-01-22
        
        // plusXXX() & minusXXX(): 给时间加减上某一时间段
        LocalDateTime localDateTime3 = localDateTime.plusMonths(3);
		LocalDateTime localDateTime4 = localDateTime.minusDays(3);
        System.out.print1n(localDateTime3); // 2023-04-26T14:23:25.428286700
        System.out.print1n(localDateTime4); // 2023-01-23T14:23:25.428286700
    }
}
```

---

#### 瞬时对象

在处理时间时，机器则是使用**时间戳**，它是时间线上的一个瞬时点，表现为**自1970年1月1日0时0分0秒(UTC)至今的秒数**，`java.time` 提供了 Instant 类来处理，它可以精确至纳秒级

```java
import java.time.*;

public class Test {
    public static void main(String[] args) {
        Instant instant = Instant.now(); // 以中时区为准，差8小时
        System.out.println(instant); // 2023-01-26T07:15:39.515749800Z

        offsetDateTime offsetDateTime = instant.atoffset(ZoneOffset.ofHours(8)); // 设置偏移量
        System.out.println(offsetDateTime); // 2023-01-26T15:19:24.224082+08:00

        long Milli = instant.toEpochMilli(); // 获取当前时间戳（毫秒级）
        System.out.println(Milli); // 1674717794320

        Instant instant1 = Instant. ofEpochMilli(1550475314878L); // 根据时间戳，获取Instant实例
        System.out.println(instant1); // 2019-02-18T07:35:14.878Z
    }
}
```

**注意：**`Instant.now()` 是以中时区为准，与东八区**差8小时**，使用时可根据需要添加偏移量

---

#### 格式化日期时间

我们使用 `java.time.format` 中 DateTimeFormatter 类来格式化时间，该类提供了三种方法：

- 预定义的标准格式：`ISO_LOCAL_DATE_TIME` ，`ISO_LOCAL_DATE` ，`ISO_LOCAL_TIME`
- 本地化相关的格式：`ofLocalizedDateTime()` ，`ofLocalizedDate()`
- 自定义的格式：`ofPattern(*yy-MM-dd hh:mm:ss E")`

```java
import java.time.*;
import java.time.format.*;
import java.time.temporal.TemporalAccessor;

public class Test {
    public static void main(String[] args) {
        LocalDateTime localDateTime = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ISO_LOCAL_DATE_TIME; // 使用预定义格式
        DateTimeFormatter formatter1 = DateTimeFormatter.ofLocalizedDateTime(FormatStyle.SHORT); // 使用本地化的格式，不止这一种
        DateTimeFormatter formatter2 = DateTimeFormatter.ofLocalizedDate(FormatStyle.FULL); // 使用本地化的格式
        DateTimeFormatter formatter3 = DateTimeFormatter.ofPattern("yyyy-MM-dd hh:mm:ss E"); // 使用自定义的格式，末尾的E代表星期
        
        // 格式化
        String str = formatter.format(localDateTime);
        String str1 = formatter1.format(localDateTime);
        String str2 = formatter2.format(localDateTime);
        String str3 = formatter3.format(localDateTime);
        System.out.println(str);  // 2023-01-26T16:12:58.8238423
        System.out.println(str1); // 2023/1/26 16:12
        System.out.println(str2); // 2023年1月26日星期四
        System.out.println(str3); // 2023-01-26 04:12:58 周四
        
        // 解析
        TemporalAccessor parse = formatter.parse("2023-01-26T15:49:50.052318");
        TemporalAccessor parse1 = formatter1.parse("2023/1/26 15:57");
        TemporalAccessor parse2 = formatter2.parse("2023年1月26日星期四");
        TemporalAccessor parse3 = formatter3.parse("2023-01-26 04:08:00 周四");
        System.out.println(parse);  // {},ISO resolved to 2023-01-26T15:49:50.052318
        System.out.println(parse1); // {},ISO resolved to 2023-01-26T15:57
        System.out.println(parse2); // {},ISO resolved to 2023-01-26
        System.out.println(parse3); // {MinuteOfHour=8, MicroOfSecond=0, MilliOfSecond=0, SecondOfMinute=0, HourOfAmPm=4, NanoOfSecond=0},ISO resolved to 2023-01-26
    }
}
```

---

#### 其他 API

| API               | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Zoneld            | 该类中包含了所有的时区信息，一个时区的ID，如Europe/Paris     |
| ZonedDateTime     | 一个在 ISO-8601日历系统时区的日期时间，如 2007-12-03T10:15:30+01:00 Europe/Paris |
| Clock             | 使用时区提供对当前即时、日期和时间的访问的时钟               |
| Duration          | 用于计算两个时间间隔                                         |
| Period            | 用于计算两个日期间隔                                         |
| TemporalAdjuster  | 时间校正器。有时我们可能需要获取例如：将日期调整到“下一个工作日”等操作 |
| TemporalAdjusters | 该类通过静态方法 (firstDayOfXxx()/lastDayOfXxx()/nextXxx()) 提供了大量的常用 TemporalAdjuster 的实现 |



### java 比较器

Java中的对象，正常情况下，只能进行 `==` 或 `!=` 的比较，不能使用 `>` 或 `<` 的，但是在开发场景中，我们需要比较对象的大小。

因此 Java 提供了两个接口来实现此功能：`Comparable` & `Comparator`

---

#### Comparable 接口

Comparable 接口实现的是自然排序，默认为**升序**，像 String，包装类等都已经实现了 Comparable 接口。

```java
public class Test implements Comparable { // 实现接口
    private int value;
    
    public Test(int value) {
        this.value = value;
    }
    
    @Override
    public int compareTo(Object o) { // 重写方法，只能返回 1 / -1 / 0
        if (o instanceof Test) {
            Test test = (Test)o;
            // 方式一
            if (this.value > test.value) {
                return 1;
            } else if (this.value < test.value) {
                return -1
            } else {
                return 0;
            }
            /* 方式二，更简单
            return Integer.compare(this.value, test.value); */
        } // 后续可以抛些异常啥的...
    }
}
```

**实现规则（升序）：**

- 如果当前对象 `this` 大于形参对象 `obj` ，则返回正整数,
- 如果当前对象 `this` 小于形参对象 `obj` ，则返回负整数,
- 如果当前对象 `this` 等于形参对象 `obj` ，则返回零。

---

#### Comparator 接口

Comparator 接口实现的是定制排序，当元素的类型**没有实现 Comparable 接口而又不方便修改代码或者实现了接口的排序规则不适合当前的操作**，那么可以考虑使用 Comparator 的对象来临时进行排序。

```java
public class Test {
    public static void main(String[] args) {
        String[] arr = new String[]{"AA", "CC", "KK" , "MM", "GG","JJ", "DD"};
        Arrays.sort(arr, new Comparator() { // 此处使用匿名实现类
            @Override
            public int compare(0bject o1, object o2) {
                if(o1 instanceof String && o2 instanceof String) {
                    String s1 = (String) 01;
                    String s2 = (String) o2;
                    return -s1. compareTo(s2); // 倒序
            	}
             // return 0;
                throw new RuntimeException("输入的数据类型不一致");
            }
        });
    }
}
```

*注：使用 Comparator 接口并未改变原有比较方式，而是在比较时使用传入的 Comparator 实现类所指定的规则来临时进行比较。*



### System 类

System 类代表系统， 系统级的很多属性和控制方法都放置在该类的内部。由于该类的构造器是 `private` 的， 所以无法创建该类的对象。其内部的成员变量和成员方法都是静态的，可直接调用。如下：

| 变量名 & 方法名   | 说明                                               |
| ----------------- | -------------------------------------------------- |
| in                | 标准输入流(键盘输入)                               |
| out               | 标准输出流(显示器)                                 |
| err               | 标准错误输出流(显示器)                             |
| currentTimeMillis | 返回当前的计算机的时间戳                           |
| exit              | 退出程序，传入的参数为零则正常退出，非零则异常退出 |
| gc                | 请求系统进行垃圾回收                               |
| getProperty       | 获得系统中属性名为所传入字符串的属性对应的值       |

系统中常见的属性名以及属性的作用如下表所示：

| 属性名       | 属性说明            |
| ------------ | ------------------- |
| java.version | Java 运行时环境版本 |
| java.home    | Java 安装目录       |
| os.version   | 操作系统的版本      |
| os.home      | 操作系统的名称      |
| user.name    | 用户的账户名称      |
| user.home    | 用户的主目录        |
| user.dir     | 用户的当前工作目录  |



### Math 类

Math 类提供了一系列**静态方法**用于科学计算。其方法的参数和返回值类型一般为 **double** & **long** 型。

| 方法名                     | 说明                     |
| -------------------------- | ------------------------ |
| abs                        | 返回绝对值               |
| acos,asin,atan,cos,sin,tan | 三角函数                 |
| sqrt                       | 开平方根                 |
| pow                        | 幂运算                   |
| log                        | 自然对数                 |
| exp                        | e 为底的指数             |
| max                        | 返回两个中的最大值       |
| min                        | 返回两个中的最小值       |
| random                     | 返回 0.0 到 1.0 的随机数 |
| round                      | 四舍五入                 |
| toDegrees                  | 弧度转角度               |
| toRadians                  | 角度转弧度               |



### BigInteger & BigDecimal 类

java.math 包的 BigInteger 类可以表示**不可变**的任意精度的**整数**，而 BigDecimal 类可以表示**不可变**的任意精度的**十进制定点数**。两者均提供所有 Java 的基本整数操作符的对应物，并提供 Math的所有相关方法。另外，BigInteger 还提供模算术、GCD计算、质数测试、素数生成、位操作等一些其他操作。

BigInteger & BigDecimal 是通过传入字符串或数值来实例化对象，如下：

```java
BigInteger a = new BigInteger("123456"); // 还能传入一个参数radix来指定该数据的进制类型，默认十进制
BigDecimal b = new BigDecimal(0.1);
```

下面是一些常用静态方法：

| 方法名            | 说明                             |
| ----------------- | -------------------------------- |
| abs               | 返回绝对值                       |
| add               | 加法                             |
| subtract          | 减法                             |
| multiply          | 乘法                             |
| divide            | 除法                             |
| remainer          | 取余                             |
| divideAndRemainer | 返回包含除法和取余两个结果的数组 |
| pow               | 幂运算                           |



## 十五、枚举类

Java 枚举是一个特殊的类，一般表示一组有限且确定的常量，如一年的 4 个季节，一个年的 12 个月份，一个星期的 7 天等。

Java 枚举类使用 `enum` 关键字来定义，各个常量使用**逗号**来分割。

```java
enum Color { RED, GREEN, BLUE;} 
```



### 基本操作

每个枚举都是通过 Class 在内部实现的，且所有的枚举值都是 `public static final` 的，所以本质还是类，可以像类一样使用，如下：

```java
enum Season {
    // 定义常量元素
 // private static final Season SPRING = Season("green"); 无枚举类时的原本写法，用枚举类后可省略为以下写法
    SPRING("green"), // 若无参，则可以省略括号，如：SPRING,
    SUMMER("yellow"),
    AUTUMN("orange"),
    WINTER("white");
    
    private final String seasonColor; // 定义属性
    
    private Season(String seasonColor) { // 构造器
        this.seasonColor = seasonColor;
    }
    
    public String getSeasonColor() { // 方法
        return seasonColor;
    }
    
 /* @Override 还可以重写该方法
    public String toString() {
        return "它是" + this.seasonColor + "的";
    } */
}

public class Test {
    public static void main(String[] args) {
        Season spring = Season.SPRING; // 其实有时候不需要创建引用，而是直接调用
        Season autumn = Season.valueOf("AUTUMN"); // 该方法由于获取指定的常量元素，没有则报错
        Season[] values = Season.values(); // 该方法用于获取枚举类所有的常量元素
        System.out.println(spring); // SPRING
        System.out.println(autumn); // AUTUMN
        System.out.println(Season.SUMMER); // SUMMER
        System.out.println(spring.getSeasonColor()); // green
        for (Season each : values) {
            System.out.println(each + " " + each.getSeasonColor());
        }
        System.out.println(Season.WINTER.toString());
    }
}
```

运行结果如下：

```
SPRING
AUTUMN
SUMMER
green
SPRING green
SUMMER yellow
AUTUMN orange
WINTER white
WINTER
```



### 实现接口

假如有以下一个接口需要用上文所创建的枚举类去实现

```java
interface printshit { void show();} // 只有一个待实现方法
```

我们可以分为两种方式去实现：

```java
enum Season implements printshit{
    // 方式二，分别实现（匿名方式）
    SPRING {
        @Override
        public void show() {
            System.out.println("fuck me");
    	}
    },
    SUMMER {
        @Override
        public void show() {
            System.out.println("fuck fuck me");
    	}
    },
    AUTUMN {
        @Override
        public void show() {
            System.out.println("fuck fuck fuck me");
    	}
    },
    WINTER {
        @Override
        public void show() {
            System.out.println("fuck fuck fuck fuck me");
    	}
    };
    
    /*// 方式一，统一实现
    @Override
    public void show() {
        System.out.println("fuck you");
    }*/
}
```

显而易见，方式一所有常量元素的 `show()` 方法都只会输出 `fuck you` ；而方式二则各不相同。



### 其他方法

除了 `values()` ，`valueOf()` ，`toString()` 这三个常用方法，Enum 类还提供了以下几个主要方法： 

| 方法名            | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| equals            | 在枚举类型中可以直接使用 “==" 来比较两个枚举常量是否相等。Enum 提供的这个 equals 方法，也是用 “==“ 实现的。它的存在是为了在 Set 、List 和 Map 中使用。注意，equals() 是不可变的 。 |
| hashCode          | 返回哈希值，用来和 equals() 保持一致。 它也是不可变的。      |
| getDeclaringClass | 得到枚举常量所属枚举类型的 Class 对象。可以用它来判断两个枚举常量是否属于同一个枚举类型。 |
| name              | 得到当前枚举常量的名称。建议优先使用 toString() 。           |
| ordinal           | 得到当前枚举常量的次序。                                     |
| compareTo         | 枚举类型实现了 Comparable 接口，这样可以比较两个枚举常量的大小(按照声明的顺序排列) |
| clone             | 枚举类型不能被 Clone。为了防止子类实现克隆方法，Enum 实现了一个仅抛出异常的不变 Clone() 。 |



## 十六、注解

Java 注解（Annotation）又称 Java 标注，是 JDK5.0 引入的一种注释机制。

Java 语言中的类、方法、变量、参数和包等都可以被标注。和 Javadoc 不同，Java 标注可以通过反射获取标注内容。在编译器生成类文件时，标注可以被嵌入到字节码中。Java 虚拟机可以保留标注内容，在运行时可以获取到标注内容 。 当然它也支持自定义 Java 标注。

---

Java 定义了一套注解，共有 7 个，3 个在 **java.lang** 中，剩下 4 个在 **java.lang.annotation** 中。

**作用在代码的注解：**

- **@Override**：检查该方法是否是重写方法。如果发现其父类，或者是引用的接口中并没有该方法时，会报编译错误。
- **@Deprecated**：标记过时方法。如果使用该方法，会报编译警告。
- **@SuppressWarnings**：指示编译器去忽略注解中声明的警告。

**作用在其他注解的注解(或者说 元注解)：**

- **@Retention**：标识这个注解的生命周期，是只在**源代码**中，还是编入 **class 文件**中，或者是在**运行时**可以通过反射访问。
- **@Documented**：标记这些注解是否包含在 Javadoc 中。
- **@Target**：标记这个注解可以修饰哪种 Java 成员。
- **@Inherited**：标记这个注解是可被子类继承的。

**从 Java 7 开始，额外添加了 3 个注解：**

- **@SafeVarargs**：Java 7 开始支持，忽略任何使用参数为泛型变量的方法或构造函数调用产生的警告。
- **@FunctionalInterface**：Java 8 开始支持，标识一个匿名函数或函数式接口。
- **@Repeatable**：Java 8 开始支持，标识某注解可以在同一个声明上使用多次。



### 基本注解

这三个注解常用在代码当中，如下所示：

```java
interface Info {
    void fuck();
}

class Shit implements Info {
    @Override // 检查是否正确重写方法
    void fuck() {
        System.out.println("Oh,fuck!");
    }
    
    @Deprecated // 表明方法已过时，不建议使用
    void shit() {
        @SuppressWarnings("unused") // 忽略变量未使用的警告
        String desire = "breast";
        System.out.println("Oh,shit!");
    }
}
```



### 自定义注解

在 Java 中自定义注解需要用到 `@interface` 修饰符，但它跟接口没啥关系。

```java
public @interface MyAnnotation {
    String value(); // 单参数形式，也可以无参数，跟@Override一样
 // String value() default "fuck"; - 还可以指定默认参数
 // String[] value() - 如果要传入多个值,可以像这样定义
}
/* 跟据自定义的类型，选择合适的形式
 * @MyAnnotation 无参或默认参数形式，作为标识
 * @MyAnnotation("hello") 传参形式
 * @MyAnnotation({"fuck", "your", "mother"}) 多参形式
 */
class Test {...}
```

**自定义注解必须配上注解的信息处理流程(使用反射)才有意义**，反射部分后续再讲。



### 元注解

元注解就是修饰注解的注解，Java 提供了四种元注解，如上文所述，示例如下：

```java
@Retention(RetentionPolicy.RUNTIME) // 标识该注解可在运行时访问
@Target({TYPE, FIELD, METHOD, PARAMETER, CONSTRUCTOR, LOCAL_VARIABLE}) // 标识该注解可标注的Java成员
@Documented // 标识该注解可包含在Javadoc中
@Inherited // 标识该注解可被所修饰的父类的子类继承
public @interface MyAnnotation {String value();}
```



### 可重复注解

这是 JDK 8 新增的一个新特性，示例如下：

```java
@interface MyAnnotations {MyAnnotation[] value();} // 先定义复数类

@Repeatable(MyAnnotations.class) // 在声明这个
public @interface MyAnnotation {String value();}

@MyAnnotation("hello")
@MyAnnotation("world") // 重复注解
class Test {...}
```

**注意**：复数类必须与原来的注解类设定相同，如：生命周期、可修饰类型等



### 类型注解

JDK 8 中 `@Target` 新增了两个修饰类型 `TYPE_PARAMETER` , `TYPE_USE`，使得注解可以应用在更多的地方，示例如下：

```java
class Generic<@MyAnnotation T> { // 需要在@Target中添加TYPE_PARAMETER
    public void show() throws @MyAnnotation RuntimeException { // 需要在@Target中添加TYPE_USE
        ArrayList<@MyAnnotation String> list = new ArrayList<>(); // 需要在@Target中添加TYPE_USE
        int num = (@MyAnnotation int) 10L; // 需要在@Target中添加TYPE_USE
    }
}
```



## 十七、集合框架

在处理大数据时，数组就显得比较垃圾，这时候就需要使用 Java 提供的集合框架来处理数据。

Java 集合可分为 Collection 和 Map 两种体系：

- Collection 接口：单列数据，定义了存取一组对象的方法的集合
    - List：元素有序、可重复的集合（ArrayList、LinkedList、Vector）
    - Set：元素无序、不重复的集合（HashSet、LinkedHashSet、TreeSet）
- Map 接口：双列数据，保存具有映射关系“键值对”的集合（HashMap、LinkedHashMap、TreeMap、Hashtable、Properties）



### Collection 接口

---

#### 内置方法

因为 Collection 是接口，其实现类都具有一样的实现方法，所以这里用 ArrayList 演示。

下面的示例展示了实现类的实例化以及一些内置方法的使用：

```java
import java.util.*;

public class Test {
    public static void main(String[] args) {
        Collection coll = new ArrayList();
        
        // add([int index,] 0bject e)：将元素e添加到集合coll中的指定位置，默认为末尾
        coll.add("AA");
        coll.add(1, "BB");
        coll.add(123); // 自动装箱
        
        // size()：获取添加的元素的个数
        System.out.println(coll.size()); // 3
        
        // addAll([int index,] Collection coll1)：将coll1集合中的元素添加到集合coll中的指定位置，默认为末尾
        Collection coll1 = new ArrayList();

        coll1.add(123);
        coll1.add(456);
        coll1.add("CC");
        coll.addAll(coll1);
		System.out.println(coll.size()); // 5
        
        // clear()：清空集合元素
		coll.clear();
        
        // isEmpty()：判断当前集合是否为空
		System.out.println(coll.isEmpty()); // true
        
        // contains(Object obj)：判断当前集合中是否包含obj（通过调用obj.equals()来判断）
		System.out.println(coll.contains("12")); // false
        
        // containsAll(Collection coll1)：判断形参coll1中的所有元素是否都存在于当前集合中
		Collection coll2 = new ArrayList(); // 返回一个ArrayList对象
        coll2.add(123);
        coll2.add(456);
		System.out.println(coll1.containsAll(coll2)); // true

		// remove(Object obj)：从当前集合中移除obj
		coll2.remove(123); // 该方法调用时会先调用contains判断是否是指定元素
        System.out.println(coll2.contains(123)); // false
        
        // removeAll(Collection coll1)：从当前集合中移除coll1中共有的所有的元素
		coll2.removeAll(coll1); // 移除456
        
        // retainAll(Collection coll1)：获取当前集合和coll1集合的交集，井修改当前集合
		coll1.retainAll(Arrays.asList("AA", "BB", "CC"));
        System.out.println(coll1); // [CC] 只有CC
        
        // equals(Object obj)：判断当前集合和obj集合的元素都是否相同，至于判断顺序相同则视集合类型而定
		coll1.add("DD");
        System.out.println(coll1.equals(Arrays.asList("CC", "DD"))); // true
        System.out.println(coll1.equals(Arrays.asList("DD", "CC"))); // false 有序集合需要判断顺序
        
        // hashCode()：返回当前对象的哈希值
		System.out.println(coll1.hashCode()); // 69601
        
        // toArray()：将集合转换为数组
        Object[] arr = coll.toArray();
        
        // iterator()：返回Iterator接口的实例，用于遍历集合元素。这个我们单独来讲
    }
}
```

---

#### 迭代器

上述代码展示了 Collection内置的 13 个常用方法，至于最后一个方法 `iterator()` ，我们首先要了解 Iterator 对象：

- Iterator 对象称为迭代器(设计模式的一种)，主要用于**遍历集合中的元素**。
- GOF 给迭代器模式的定义为：提供一种方法**访问一个容器(container)对象中各个元素，而又不需暴露该对象的内部细节**。迭代器模式，就是为容器而生。类似于“公交车上的售票员”、“火车上的乘务员”、“空姐 ”
- Collection 接口继承了 java.lang.lterable 接口，该接口有一个 `iterator()` 方法，那么所有实现了 Collection 接口的集合类都有一个 `iterator()` 方法，用以返回一个实现了 Iterator 接口的对象。
- Iterator 仅用于遍历集合，Iterator 本身并不提供承装对象的能力。**如果需要创建 Iterator 对象，则必须有一个被迭代的集合**。
- 集合对象每次调用 `iterator()` 方法都得到一个全新的迭代器对象，默认游标都在集合的第一个元素之前。

```java
import java.util.*;

public class Test {
    public static void main(String[] args) {
        Collection coll = new ArrayList();
        coll.add("AA");
        coll.add("BB");
        coll.add(123);
        Iterator iterator = coll.iterator(), iterator1 = coll.iterator(), iterator2 = coll.iterator();
        Iterator iterator3 = coll.iterator();
        // next()：返回下一个元素
        System.out.println(iterator.next()); // AA
        System.out.println(iterator.next()); // BB
        System.out.println(iterator.next()); // 123
        
        for (int i = 0; i < coll.size(); i++) { // 可以避免游标越界，但不常用
        	System.out.println(iterator1.next());
        }
        // hasNext()：判断是否存在下一个元素
        while (iterator2.hasNext()) { // 常用方式，也常用ForEach循环
            System.out.println(iterator2.next());
        }
        
        // remove()：从集合中删除当前元素
        while (iterator3.hasNext()) {
            if (iterator2.next().equals("BB")) {
                iterator3.remove(); // 从集合中删除BB
            }
        }
    }
}
```

**注：Iterator 仅用于 Collection ，不用于 Map**

---

#### List 接口

该接口用于存储**有序的、可重复**的数据。 相当于“动态”数组，会替换原有的数组，其实现类有如下三个：

- ArrayList：作为 List 接口的主要实现类；**线程不安全的，效率高**；底层使用 `Object[] elementData` 存储
    - 使用空参构造器时，底层会在调用 `add()` 时才创建一个 `Object[10] elementData` 来储存
    - 当添加的元素数量大于数组容量，则会将容量扩大 1.5 倍
    - 开发中使用，建议提前指定容量，避免扩容
- LinkedList：**对于频繁的插入、删除操作，使用此类效率比 ArrayList 高**；底层使用双向链表存储
    - 内部声明了 Node 类型的 `first` 和 `last` 属性，默认值为 null
    - 每次 `add()` 都会把数据封装到节点中并连接到链表里
- Vector：作为 List 接口的古老实现类；**线程安全的，效率低**；底层使用 `Object[] elementData` 存储 
    - 使用空参构造器时，就创建一个 `Object[10] elementData` 来储存
    - 相比于 ArrayList ，扩容时会扩大 2 倍
    - 添加了 `synchronized` 的 ArrayList ，几乎没人用了......

---

List 除了从 Collection 集合继承的方法外，List 集合里添加了一些根据索引来操作集合元素的方法。

| 方法                                           | 说明                                     |
| ---------------------------------------------- | ---------------------------------------- |
| **void add(int index, Object ele)**            | 在 index 位置插入 ele 元素               |
| **boolean addAll(int index, Collection eles)** | 从 index 位置开始将 eles 中              |
| **Object get(int index)**                      | 获取指定 index 位置的元素                |
| **int indexOf(Object obj)**                    | 返回 obj 在集合中首次出现的位置          |
| **int lastlndexOf(Object obj)**                | 返回 obj 在当前集合中末次出现的位置      |
| **Object remove(int index)**                   | 移除指定 index 位置的元素，并返回此元素  |
| **Object set(int index, Object ele)**          | 设置指定 index 位置的元素为 ele          |
| **List subList(int fromIndex, int tolndex)**   | 返回从 fromIndex 到 tolndex 位置的子集合 |
*注：使用 List 类型创建引用，即可调用这些方法*

---

#### Set 接口

该接口用的比较少，用于存储**无序的、无重复**的数据。Set 接口判断两个对象是否相同不是使用 == 运算符，而是根据 `equals()` 方法。

- 无序性：等于随机性。存储的数据在底层数组中并非按照数组索引的顺序添加，而是根据数据的哈希值排序
- 不可重复性：保证添加的元素按照 `equaLs()` 判断时，不能返回 `true` ，即相同的元素只能添加一个

其实现类有如下三个：

- HashSet：作为 Set 接口的主要实现类；**线程不安全的**；可以存储 null 值
    - 内部使用 HashMap 实现的
- LinkedHashSet：作为 HashSet 的子类；遍历其内部数据时，**可以按照添加的顺序遍历**
    - 在添加数据的同时，每个数据还维护了两个引用(双向链表)，记录此数据前一个数据和后一个数据
    - 对于频繁的遍历操作，LinkedHashSet 效率高 HashSet
- TreeSet：可以按照添加对象的指定属性**自动进行排序**，遍历结果默认为升序
    - 因为涉及排序，所以要求添加的数据是相同类的对象，且所属类必须实现两个排序接口
    - 自然排序中，比较两个对象是否相同的标准为 `compareTo()` ，而不再是 `equals()`
    - 定制排序中，可以将 Comparator 对象作为构造器参数传入，从而改变比较标准为 `compare()`

---

**Set 接口添加元素的过程：**

1. 向 HashSet 中添加元素 a
2. 获取元素 a 的 hash 值
3. 此哈希值通过某种算法计算出底层数组中的存放位置
4. 判断数组此位置上是否已经有元素:
    1. 如果此位置上没有其他元素，则元素 a 添加成功
    2. 如果此位置上有其他元素 b (或以链表形式存在的多个元素)，则比较元素 a 与元素 b 的 hash 值:
        1. 如果 hash 值不相同，则元素 a 添加成功
        2. 如果 hash 值相同，进而需要调用元素 a 所在类的 equlas 方法:
            1. `equals()` 返回 `true` ，元素 a 添加失败
            2. `equals()` 返回 `false` ，则元素 a 添加成功

综上所述，Set 接口添加元素需要用到 `hashCode()` 和 `equals()` ，因此向 Set 中添加的数据，其所在的类一 定要重写这两个方法，且尽可能保证一致性。

*注：Set 接口没有添加额外的方法，只有继承来的方法*



### Map 接口

该接口由于存储双列数据，也就是 key-value 对的数据，相当于 Python 的字典

- Map 中的 key：**无序的、不可重复的**，使用 Set 存储所有的 key（记得重写 equals 和 hashCode）
- Map 中的 value：**无序的、可重复的**，使用 List 存储所有 的 value（记得重写 equals）
- Map 中的 entry：无序的、不可重复的，使用 Set 存储所有的 entry（一个键值对构成了一个 Entry 对象 ）

其实现类有如下五个：

- HashMap：作为Map的主要实现类；**线程不安全的，效率高**；**能存储 null 的 key-value 对**；底层用**数组**+**链表**+**红黑树**存储
    - 使用空参构造器时，底层会在调用 `put()` 时才创建一个 `Node[16] table` 来储存
    - 在添加键值对时，会先按照 Set 接口的方式添加 key，再按 List 接口的方式添加 value；若添加相同的 key ，则会**覆盖**原有的值
    - 当添加的元素数量大于数组容量，则会将容量扩大 2 倍
    - 当数组的某一索引位置上用链表存储 **8** 个以上的数据且数组长度 > **64** 时，此时此索引位置上的所有数据改为使用**红黑树**存储
- LinkedHashMap：作为 HashMap 的子类；保证在遍历元素时，可以按照添加的顺序实现遍历
    - 底层用了双向链表，对于频繁的遍历操作，此类执行效率高 HashMap
- TreeMap：保证按照添加的 key-value 对进行排序，实现排序遍历。
    - 因为涉及排序，所以要求添加的 key 是相同类的对象，且所属类必须实现两个排序接口
    - 至于如何排序，则与 TreeSet 相同
    - 与 TreeSet 一样，底层使用红黑树，要考虑自然排序和定制排序
- Hashtable：作为古老的实现类；**线程安全的，效率低**；**不能存储 null 的 key-value 对**
    - 添加了 `synchronized` 的 HashMap ，不咋用...
- Properties：作为 Hashtable 的子类；常用来处理配置文件。key 和 value 都是 String 类型

---

#### 内置方法

因为 Map 是接口，其实现类都具有一样的实现方法，所以这里用 HashMap 演示。

下面的示例展示了实现类的实例化以及一些不同于 Collection 的内置方法的使用：

```java
import java.util.*;

public class Test {
    public static void main(String[] args) {
        Map map = new HashMap();
        
        // put(0bject key, 0bject value)：将键值对(key,value)添加到集合coll中的指定位置
        map.put("name", 123);
        map.put(456, "age");
        map.put("name", 789); // 修改，覆盖原有的值
        
        // size()：获取添加的元素的个数
        System.out.println(map.size()); // 2
        
        // putAll(Map map1)：将map1集合中的元素添加到集合map中的指定位置
        Map map1 = new HashMap();
        map1.put(1, "Oh");
        map1.put("shit", 2);
        map.putAll(map1);
		System.out.println(map.size()); // 4
        
        // get(Object key)：获取指定key对应的value
		System.out.println(map.get("shit")); // 2
        
        // containsKey(Object key)：判断当前集合中是否包含指定的key
		System.out.println(map.containsKey("12")); // false
        
        // containsValue(Object value)：判断当前集合中是否包含指定的value
		System.out.println(map.containsValue(789)); // true

		// remove(Object key)：从当前集合中移除key所属的键值对并返回其value；若集合中没有key，则返回null
        System.out.println(map.remove(456)); // age
        System.out.println(map); // 移除了456=age
        
        // keySet()：返回由所有key组成的Set对象
        Set set = map.keySet();
        Iterator iterator = set.iterator();
        while(iterator.hasNext()) {
        	System.out.println(iterator.next()); // 遍历所有的key集
        }
        
        // values()：返回所有value组成的Collection对象
        Collection values = map.values();
        for(Object obj : values) {
        	System.out.println(obj); // 遍历所有的value集
        }
        
        //entryset()：返回由所有key-value组成的Set对象
        Set entrySet = map.entrySet();
        Iterator iterator1 = entrySet.iterator();
        while (iterator1.hasNext()) {
            Map.Entry entry = (Map.Entry)iterator1.next(); // entrySet集合中的元素都是entry
            System.out.println(entry.getKey() + "-" + entry.getValue());  // 遍历所有的key-value集
        }
        
        // hashCode()：返回当前对象的哈希值
        
        // clear()：清空集合元素
        
        // isEmpty()：判断当前集合是否为空
        
        // equals(Object obj)：判断当前集合和obj是否相同
        
    }
}
```

*注：以上只展示不同方法，相同方法仅标明*

---

#### Properties 的使用

Properties 类是 Hashtable 的子类，该对象用于**处理属性文件**；由于属性文件里的 key 、value 都是字符串类犁，所以 Properties 里的key 和 value 都是字符串类型；存取数据时，建议使用 `setProperty(String key,String value)` 和 `getProperty(String key)` 。

假设该 java 文件同目录下存在一个配置文件 `jdbc.properties` ，内容如下：

```java
// 注意不要有多余空格！
name=shit
age=18
```

下面的代码简单地展示了如何读取配置文件：

```java
Properties pros = new Properties();
fis = new FileInputStream("jdbc.properties"); // 文件操作，注意捕获异常
pros.load(fis); // 加载流对应的文件
String name = pros.getProperty("name"), age = pros.getProperty("age");
System.out.println("name = " + name + ", age = " + age); // name = shit, age = 18
```



### Collections 工具类

Collections 是一个操作 **Collection** 和 **Map** 等集合的工具类，它提供了一系列静态的方法对集合元素进行排序、查询和修改等操作，还提供了对集合对象设置不可变、对集合对象实现同步控制等方法

常用方法如下：

| 方法                                                         | 说明                                                     |
| ------------------------------------------------------------ | -------------------------------------------------------- |
| **reverse(List list)**                                       | 反转 list 中元素的顺序                                   |
| **shuffLe(List list)**                                       | 对 list 中元素的进行随机排序                             |
| **sort(List list[, Comparator com])**                        | 根据元素的自然顺序或定制排序对指定 list 中的元素进行排序 |
| **swap(List list, int i, int j)**                            | 将指定 list 中的 i 处元素和 j 处元素进行交换             |
| **Object max(Collection coll[, Comparator com])**            | 根据元素的自然顺序或定制排序，返回给定集合中的最大元素   |
| **Object min(Collection coll[, Comparator com])**            | 根据元素的自然顺序或定制排序，返回给定集合中的最小元素   |
| **int frequency(Collection coll, Object obj)**               | 返回指定集合中指定元素的出现次数                         |
| **copy(List dest, List src)**                                | 将 src 中的内容复制到 dest 中                            |
| **boolean replaceAll(List list, Object oldVal, Object newVal)** | 使用 newVal 替换 list 中所有的 oldVal 元素               |

Collections 类中提供了多个 `synchronizedXxx()` 方法，该方法可使**将指定集合包装成线程同步的集合**，从而可以解决多线程并发访问集合时的线程安全问题，如下：

```java
List list1 = Collections.synchronizedList(list); // 返回的list1即为线程安全的List对象
```

当然，也有 Set ，Map 的方法，这里就不多赘述



## 十八、泛型

Java 泛型（generics）是 JDK 5 中引入的一个新特性，就是允许在定义类、接口时通过一个**标识**表示类中某个属性的类型或某个方法的返回值及参数类型，这个**泛型类型**将在使用时确定。



### 使用泛型

我们可以在集合中使用泛型，如下：

```java
public static void main(String[] args) {
    ArrayList<Integer> list = new ArrayList<Integer>();
    list.add(123);
 // list.add("fuck"); 编译不通过
    
    HashMap<String,Integer> map = new HashMap<>(); // 双参泛型，其实后面的泛型可省略，反正和前面一样
    map.put("A", 1);
 // map.put(2, "B"); 编译不通过
    Set<Entry<String,Integer>> entry = map.entrySet(); // 因为返回值也是泛型嵌套结构，所以也要用泛型创建引用
}
```

**注意事项：**

- 集合接口或集合类在 JDK 5.0 时都修改为带泛型结构，所以在实例化集合类时，需指明具体的泛型类型
- 指明后，在集合类或接口中凡是定义类或接口时，内部结构用到泛型的位置都指定为实例化所传入的类型
- 泛型类型必须是类，不能是基本数据类型，但可以用包装类代替，如上面的 `Integer`
- 若没有指明泛型类型，则默认类型为 `Object`
- **泛型不同的引用不能相互赋值**，如 `ArrayList<Integer>` 和  `ArrayList<String>` 



### 自定义泛型

自定义泛型的过程其实很简单，只需要把不确定的类型用泛型类型代替即可，示例如下：

```java
public class Test<T> { // 第一种用法：自定义泛型类
    T unknowData; // 用泛型类型声明未知变量
    static int[] arr = {1, 2, 3, 4};
    
    public Test(T unknowData) { // 用泛型类型声明形参，这不是泛型方法
        this.unknowData = unknowData;
        List<Integer> list = Test2(arr); // 指明泛型方法的泛型类型
    }
    // 第三种用法：自定义泛型方法
    public static <E> List<E> Test2(E[] arr) {...} // 其泛型类型与类的无关，所以可以是静态的
}
public interface Test1<T>; // 第二种用法：自定义泛型接口
```
**注意事项：**

- **异常类和静态方法中不能使用泛型类型**，后者是因为还没实例化传入类的泛型类型，但是**泛型方法可以是静态的**
- **不能直接使用泛型类型创建数组**，只能 `T[] arr = (T[]) new Object[10]` 这样来间接创建



### 泛型的继承

泛型的继承情况有点复杂，这里只讲解两点可能会出现的情况。

---

#### 泛型的子父类关系

具体分为两种情况：`G<A>` & `G<B>` 和 `A<G>` & `B<G>`

```java
public void test1() {
    // 虽然类A是类B的父类，但是G<A>和G<B>二者不具备子父类关系，二者是并列关系
    List<Object> list1 = null;
    List<String> list2 = null;
 // list1 = list2; 编译不通过
    // 如果类A是类B的父类，则A<G>就是B<G>的父类，二者是父子关系
    List<String> list3 = null;
    ArrayList<String> list4 = null;
    list3 = list4; // 编译通过
}
```

*注：情况一也对应了注意事项中所说的：**泛型不同的引用不能相互赋值***

---

#### 泛型的保留

在父类使用泛型的情况下，子类在继承时可以选择**全保留**和**部分保留**父类的泛型或是**重定义**泛型

```java
class Father<T1,T2> {}

// 子类不保留父类的泛型，直接指明父类的泛型类型就可以保证子类继承的是已经确定的类型而不是泛型
class Son1 extends Father {} // 默认Object类型

class Son2 extends Father<Integer,String> {} // 具体类型

// 子类保留父类的泛型，父类的泛型类型是否指明可决定子类是否继承泛型
class Son3<T1,T2> extends Father<T1,T2> {} // 全保留

class Son4<T2> extends Father<Integer,T2> {} // 部分保留
```



### 通配符

在上文我们讲到泛型不同的引用不具有父子关系，这导致值传递时无法使用多态性，我们不得不多写几个方法重载，那样十分繁琐。因此 Java 提供了通配符 `?` 来作为两者的共同“父类”来实现多态性。

```java
public void test(){
    List<Object> list1 = null;
    List<String> list2 = null; 
    List<?> list = null;
    
    // 作为两者的共同“父类”
    list = list1; // 编译通过
    list = list2; // 编译通过
    
    // 对于List<?>，除了null以外，不能向其内部添加其他数据
 // list.add("shit"); 编译不通过
    
    // 但可以读取数据且只能为Object
    Object o = new list.get(0); // 编译通过
}
```

Java 还允许我们对通配符加上限制条件，有三种用法：`<? extends 类>` 、`<? super 类>` 、`<? extends Comparable>`

```java
// Person是Student的父类
public void test() {
    List<? extends Person> list1 = null; // (-∞, Person]，读取数据可以用Person作引用
    List<? super Person> list2 = null; // [Person, +∞)，读取数据只能为Object
    List<Student> list3 = null;
    List<Person> list4 = null;
    List<Object> list5 = null;

    list1 = list3;
	list1 = list4;
 // list1 = list5; 编译不通过
 // list2 = list3; 编译不通过
	list2 = list4;
	list2 = list5;
	// 以下为写入操作的差异
 // list1.add(new Student()); 编译不通过
    list2.add(new Person()); 
	list2.add(new Student());
}
```

第三种用法**只允许泛型为实现 Comparable 接口的实现类的引用调用**，这里仅说明就不展示了。



## I/O 流

Java.io 包几乎包含了所有操作输入、输出需要的类。所有这些流类代表了输入源和输出目标。一个流可以理解为一个数据的序列。输入流表示从一个源读取数据，输出流表示向一个目标写数据。



### File 类的使用

File 类的一个对象，代表一个**文件**或一个**文件目录**，其中涉及到关于文件或文件目录的创建、删除、重命名、修改时间、文件大小等方法

---

#### 实例化

下面的示例展示了 File 的三种实例化方式：

```java
import java.io.File;
public void test() {
    // 构造方式一
	File file1 = new File("D:\\fuck\\shit\\hello.txt"); // 完整绝对路径（也支持相对路径）
	System.out.println(file1); // 只是输出路径
    
    // 构造方式二
    File file2 = new File("D:\\fuck", "shit"); // 分开传入父目录及文件目录
    
    // 构造方式三
    File file3 = new File(file2, "hello.txt"); // 分开传入file对象及文件
}
```

*注：创建实例时，不管文件或目录是否存在，仅在内存方面先创建一个对象，并不会报错*

---

#### 常用方法

File 类的方法主要分为五部分：获取、重命名、判断、创建、删除。

```java
import java.io.File;
public void test() {
    File file1 = new File("hello.txt");
    File file2 = new File("D:\\fuck\\shit");
    File file3 = new File(file2, "hello.txt");
    File file4 = new File("shit.txt");
        
    // 获取方法
    System.out.println(file1.getAbsolutePath()); // 获取绝对路径
    System.out.println(file1.getPath()); // 获取路径（传给构造器的路径）
    System.out.println(file1.getName()); // 获取文件名
    System.out.println(file1.getParent()); // 获取父目录（根据传给构造器的路径查找）
    System.out.println(file1.length()); // 获取文件长度（字节数）不能获取文件目录长度
    System.out.println(file1.lastModified()); // 获取最后一次修改时间（时间戳）
    System.out.println(file2.list()); // 获取指定目录下的所有文件或者文件目录的名称数组（字符串数组）
    System.out.println(file2.listFiles()); // 获取指定目录下的所有文件或者文件目录的File类型数组
        
    // 重命名方法（要想保证返回true,需要file1是存在的，且file3是不存在的）
    System.out.println(file1.renameTo(file3)); // 把文件重命名为指定的文件路径（可修改的不仅是名称，还有路径）
        
    // 判断方法（若文件不存在，以下皆为false）
    System.out.println(file1.isDirectory()); // 判断是否是文件目录
    System.out.println(file1.isFile()); // 判断是否是文件
    System.out.println(file1.exists()); // 判断是否存在
    System.out.println(file1.canRead()); // 判断是否可读
    System.out.println(file1.canWrite()); // 判断是否可写
    System.out.println(file1.isHidden()); // 判断是否隐藏
        
    // 创建和删除方法
    file4.createNewFile(); // 创建该文件（若文件存在，则返回false）
    file4.delete(); // 彻底删除该文件（若文件不存在，则返回false）
    file2.mkdir(); // 创建文件目录（若文件目录存在或文件目录的上级目录不存在，则返回false）
    file2.mkdirs(); // 递归创建文件目录（若文件目录存在，则返回false；若文件目录的上级目录不存在，则一并创建）
}
```



### 流的抽象基类

Java 提供的 I/O 流光类就有 40 多个，但它们都继承于四个抽象基类：`InputStream` 、`OutputStream` 、`Reader` 、`Writer` ，接下来我们将分别讲述他们的子类。

---

#### Reader

顾名思义是输入流，用来读取数据，常用的子类是 FileReader 用来从文件中读取数据，实例如下：

```java
public void test() {
    FileReader fr = null;
    try { // 文件操作会抛出IOException异常，要注意捕获
        File file = new File("hello.txt"); // 实例化File类的对象，指明要操作的文件
        fr = new FileReader(file); // 提供具体的流，若文件不存在，则报错
        
        // 方式一：read() - 返回读入的一一个字符。如果达到文件末尾，返回-1 
        int data; 
        while((data = fr.read()) > 0) // 数据的读入
            System.out.println((char)data);
        
        // 方式二：read(char[] cbuf) - 返回每次读入cbuf数组中的字符的个数。如果达到文件末尾，返回-1
        int len;
        char[] cbuf = new char[5];
        while((len = fr.read(cbuf)) > 0) {
            // 常规写法
            for (int i = 0; i < len; i++)
            	System.out.print(cbuf[i]);
            // 简易写法
            String str = new String(cbuf, 0, 1en);
			System.out.print(str);
        }
        
        // 方式三：read(char cbuf[], int off, int len) - 返回每次读入cbuf数组中限定位置的字符的个数。
    	// 也是达到文件末尾，返回-1；不过这个不常用，不展示
    } catch (IOException e) {
        // 异常处理
    } finally { // 确保流能正常关闭
        try {
            if (fr != null) fr.close(); // 流的关闭操作，它也会抛出IOException异常
        } catch (IOException e) {
        // 异常处理
        }
    }
}
```

---

#### writer

这个是用来写入数据的，常用的是 FileWriter，示例如下：

```java
public vo1d test() {
    File file = new File("hello1.txt"); // 若文件不存在，则直接新建
    FileWriter fw = new FileWriter(file, false); // 后一个参数代表是否添加数据，不然直接覆盖，默认为false
    fw.write("I have a dream!"); // 往文件写数据
    fw.close();
}

```

