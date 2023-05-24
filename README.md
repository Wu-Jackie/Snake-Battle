# Overwatch_fan-made_version_Minesweeper

**守望先锋同人版扫雷**

大一C课设，致敬曾经热爱的Overwatch[^1]

## 故事背景

多年之前，在“智械危机”结束之后，一群被放逐的智能机器人感受到了被其称为“灵魂觉醒”的升华之道。他们放弃了自己被预先设定好的生活，在喜马拉雅山深处建立起了一座寺庙。在冥思其存在本质和意义多年之后，他们渐渐相信他们不止是人工智能而已，和人类一样，他们也有灵魂。在意识到他们在灵魂层面与人类一样后，由神秘僧侣泰哈撒·孟达塔带领的这些僧侣开始寻找治愈一个世代前，由“智能危机”所留下的创伤，并希望让人类和机器人重回曾经的和谐相处之道。他们最终被世人所接纳，且他们的信念也得到了全球数百万人的支持。

为了弥补人类和智械之间的创伤，并重回曾经的和谐相处之道，泰哈撒·孟达塔作为智械的温和派精神领袖一直努力着。由于西伯利亚再次发生了智械与人类的冲突，泰哈撒·孟达塔为此发表演说，呼吁和平，在演说的过程中遭到隶属“黑爪”的黑百合暗杀，虽然得到了猎空的帮助，但仍然中枪倒地，生死未卜。此次事件影响重大，可能导致第二次“智械危机”，为此守望先锋再次集结。而玩家则是守望先锋中的一员。这次玩家与游走于世界寻找灵魂升华之道的机械僧侣禅雅塔一道回到神秘的香巴里寺院，却遇到邪恶的弗兰狂斯鼠博士掠夺香巴里寺院，香巴里寺院需要你的帮助，禅雅塔将玩家在的帮助下扫描出弗兰狂斯鼠博士埋的地雷，解救香巴里寺院与其一众僧人。

## 游戏说明


确定大小的矩形雷区中随机布置一定数量的地雷(10\*10个方块10个雷)，玩家需要尽快找出雷区中的所有不是地雷的方块，而不许踩到地雷。

游戏的基本操作包括左键单击、右键单击两种。左键用于打开安全的格子，推进游戏进度；右键用于标记地雷，以辅助判断。

- 左键单击

在判断出不是雷的方块上按下左键，可以打开该方块。如果方块上出现数字，则该数字表示其周围3×3区域中的地雷数（一般为8个格子，对于边块为5个格子，对于角块为3个格子）；如果方块上为空（相当于0），则可以递归地打开与空相邻的方块；如果不幸触雷，则游戏结束。

- 右键单击

在判断为地雷的方块上按下右键，可以标记地雷（显示为小红旗）。再次点击已被标记的地雷可取消标记。

若触雷导致游戏结束，则可在禅雅塔的鼓励下选择重试或者直接退出；全部找出雷则游戏胜利。

## 注意事项

1. 我的运行环境为visual studio 2022

2. 该项目需先下载[EasyX图形库](https://easyx.cn/)

3. 在项目-属性-配置属性-高级-字符集中改为“使用多字节字符集”

4. .ico导入后会自动生成resource.h，所以无需手动添加

## 设计内容

《守望先锋同人版扫雷》在基于**EasyX图形库**的基础上实现了对游戏的操作，还成功将带有守望先锋元素的图片与音效/音乐插入到该游戏中，让玩家尤其是曾经的守望先锋玩家沉浸其中，在游戏过程中也可以感受禅雅塔对我们的教诲，习得人生道理。具体主要功能如下：

1. 实现展示图形化界面。

2. 实现鼠标与程序的交互。

3. 利用递归实现扫雷游戏特色——若点开空白区域炸开一片。

4. 利用time.h与相关函数随机生成地雷于地图。

5. 实现判断胜负，利用MessageBOX生成新的消息框，增加趣味性。

## 深度优化

1. 从官方网站运用Photoshop抠出守望先锋Logo，并制作.ico文件，完善图形界面，增加观感

实操：解决方案资源管理器中右键->资源文件-添加-资源，资源类型选择icon，导入库中的.ico文件

2. 利用Enigma Virtual Box对可执行文件（.exe）打包封装

### Enigma Virtual Box的使用

[软件下载地址](https://enigmaprotector.com/cn/downloads.html)。

安装完成后进入软件

![](https://img-blog.csdnimg.cn/9b2931e2c1b046878b0d520a5c9b60b1.png)

1. 点击<kbd>enter input file name</kbd>右侧的<kbd>browse</kbd>，选中待打包的软件

2. 点击左下角<kbd>Add</kbd>的<kbd>add folder recursive</kbd>，在弹出来的对话框选择待打包文件夹

3. 点击右下角的<kbd>files options</kbd>，勾选<kbd>compress files</kbd>

4. 点击<kbd>process</kbd>开始打包

# ※存在的问题及后续的改进

1. 游戏只能玩一局，即点中雷后无法选择新的一局

2. 希望加入不同难度

3. 随着难度的提高，雷数也逐渐增多，当玩家标记雷时可能存在忘记有多少的情况，后续希望增加对雷数的显示

希望有大佬看到后在此基础上做出修改，并push给我，完善这个项目！谢谢大佬！

# 写在最后

Overwatch陪伴了我很久，**这个世界需要更多的英雄！**(T^T)

游戏会离去，但英雄不朽

我受到了召唤，一如既往





[^1]: 最熟的英雄是狂鼠和禅雅塔，所以以此为蓝本制作了该游戏