# Neural Cognitive Diagnosis for Intelligent Education Systems --���

## ��������ѧϰ��������֪���NeuralCD��NeuralCD+

## NeuralCD
![](images/2023-02-21-13-30-51.png)

    ����һ�����ϵͳ��Ҫ��������Ԫ�أ�ѧ�����أ���ϰ�����أ��Լ����ߵĻ�������ͼ��NeuralCD�Ŀ�ܡ�

## NeuralCDM
NeuralCDM��NeuralCD����µ�һ��ģ�ͣ���NeuralCDM�У�ÿ��ѧ������һ��֪ʶ������������ʾ��

**Student factor** $F_s$��[(1��0)]��ʾѧ����ĳ��֪ʶ������ճ̶ȣ�����[(0.9,0.2)]���ʾ�Ե�һ��֪ʶ�����սϺã����Եڶ���֪ʶ�����ղ��㣬������$h_s$������$h_s$����ѧ����one-hot��ʾ����$x^s$��һ����ѵ����������A������á�

$$\begin{matrix}
    h_s=sigmoid(x^s*A)
\end{matrix}$$
$h_s\in${0,1}$^{1*K}$,$x^s\in${0,1}$1*N$,$A\in R^{N*K}$

**Excersize factor** 
