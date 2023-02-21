# Neural Cognitive Diagnosis for Intelligent Education Systems --王淇

## 提出了深度学习方法的认知诊断NeuralCD和NeuralCD+

## NeuralCD
![](images/2023-02-21-13-30-51.png)

    对于一个诊断系统需要考虑三个元素：学生因素，练习题因素，以及两者的互动。上图是NeuralCD的框架。

## NeuralCDM
NeuralCDM是NeuralCD框架下的一种模型，在NeuralCDM中，每个学生都用一个知识熟练度向量表示。

**Student factor** $F_s$是[(1，0)]表示学生对某个知识点的掌握程度，例如[(0.9,0.2)]则表示对第一个知识点掌握较好，但对第二个知识点掌握不足，下面用$h_s$表述。$h_s$是由学生的one-hot表示向量$x^s$和一个可训练向量矩阵A相乘所得。

$$\begin{matrix}
    h_s=sigmoid(x^s*A)
\end{matrix}$$
$h_s\in${0,1}$^{1*K}$,$x^s\in${0,1}$1*N$,$A\in R^{N*K}$

**Excersize factor** 
