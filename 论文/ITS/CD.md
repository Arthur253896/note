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

## һ�����ڿɽ�����֪���ģ�͵����Ͷ�����ϵ������ --����� sciһ�� QRCDM  

1������ֽ⣬QRCDM�����ھ���ֽ⡣

1.1 ����ֽ⣨MF����һ�ֳ��������Ƽ�ϵͳ�ж��û�����Ŀ���н�ģ�ķ���������о���Ա֤���� MF ��ѧϰ����֪״̬��ģ�Ŀ����ԡ���ʹ�� MF ��ѧϰ�ߵ���֪״̬���н�ģʱ����ѧϰ����Ϊ�û�������ϰ��Ϊ��Ŀ������������ϰ�еı�����Ϊ�û�����Ŀ�ķ�Ӧ��
���еľ���ֽ���Ȼ��Ԥ��ѧϰ�ߵ�ϰ�������һ�����ã����ֽ������е����������֪ʶ����֮��û����ȷ�Ķ�Ӧ��ϵ [7]����˲���������֪��ϡ�

    2.֪ʶ׷��
    ֪ʶ���٣�KT������ͨ����������ÿ��ѧϰ�ߵ�֪ʶ״̬��Ԥ��ѧϰ����δ��ʵ����еı��֡�
    ֪ʶ׷�ٸ����ĵ���Ԥ��ѧϰ����ȷ�����һ����ϰ�ĸ��ʡ�����Ҫ���ǣ�֪ʶ������ MF �� KT ���ǷǱ�Ҫ���ء�

## ���� 
����ֽ⣨MF��ּ��ͨ��ѧϰ������ϰ����һ�����еı�����Ԥ��ѧϰ������ϰ��һ�����еı��֡�֪ʶ���٣�KT����һ�����ѧϰ���ڹ�ȥ�����׶���ϰ�б��ֵ�������Ԥ��������δ����ϰ��еı��֡��� MF ��ͬ��ʱ���� KT �е�һ����Ҫ���ء�

��֪��ϸ���ע��ȡѧϰ�ߵ���֪״̬��Ϊ������ѧϰ�ߵ���֪״̬������ʵ����ѧϰ�ߵ���֪״̬Ԥ��ѧϰ����ȷ�����һ����ϰ�ĸ��ʡ��ӻ���ѧϰ�ĽǶ����֪ʶ��Դģ�;�����׼ȷ��Ԥ��ѧϰ����ȷ�ش���һ��ĸ��ʡ�����̫����ѧϰ�ߵ���֪״̬��ֻҪ������׼ȷ��Ԥ��ѧϰ����ȷ�ش���һ����ϰ��ĸ��ʼ��ɣ���֪ʶ׷�ٸ�����Ԥ��ѧϰ�߻����һ����ϰ��ĸ�����ϰ����Ȩ����

���е���֪���ģ�ͺ��ٳ������ϰ����֪ʶ����֮���������ϵ����ѧϰ�ߵ�֪ʶ״̬����ֱ�ۡ��ɽ��͵���ϡ���ˣ����о������һ�ֳ�ֽ����ϰ��֪ʶ����֮�����Ժ����Թ�ϵ�Ķ�����ϵ��֪���ģ��


## ��֪��Ϻ�֪ʶ׷�ٵ���ͬ
��֪�������һ���������۵Ĵ�����Ŀ�����ܹ���ѧ������Χ��֪ʶ��������������������õ�ѧ���ڲ�֪ͬʶ��Χ�ϵ�ѧϰˮƽ�����д����ģ���ǣ�DINA,Q���󣩸þ�����ÿһ����ϰ���֪ʶ��Χ, ��һ����ʾ��֪ʶ/���ܱ�ʾ��
ͼ 2.4(a)չʾ��һ��Q���������, ���п��Կ�����ϰ�� 2 ������ ���ӷ��� �� ���˷��� ����֪ʶ�㡣��ʵ��Ӧ����Q����ͨ���ɽ���ѧר�� (���ʦ) ���б�ע��
![](20230313110311.png)

��֪����Ǿ۽���ѧ��Ŀǰ����ĳ��֪ʶ������ճ̶ȣ���Ҫ����ϰ���֪ʶ֮��Ĺ�ϵ��
֪ʶ׷���Ǿ۽���ѧ�����´δ��������Ŀ���ʣ����������ص㲻һ����
֮ǰ���뷨���ó����ڼ�������ȥԤ��ѧ���´δ��������Ŀ�ĸ��ʣ������ص�͸���ˣ������Ѿ�����ص����ģ������ڿ����������о�DKT����ȣ�
������֪���ͨ���Ǵ�֪ʶ���ϰ���Ѷ�����ά��Ԥ�⣬�Ҿ��ſ��Լ�һ��ʱ��ά�ȣ����ڲ�ͬʱ���ѧ������һ������Ϥ�ȵ�ά�ȣ���ѧϰ��֪ʶ��ʱ��ʹ������ĳ̶�������������ϼ������ߵ�ʱ��ڵ㣬����һ����Ϥ�ȵķ�����������ۺϳ���ѧ��Ŀǰ��֪ʶ���档

����ֽ⣨MF��ּ��ͨ��ѧϰ������ϰ����һ�����еı�����Ԥ��ѧϰ������ϰ��һ�����еı��֡�֪ʶ׷�٣�Knowledge tracking��KT����һ��׷��ѧϰ���ڹ�ȥ�����׶���ϰ�б��ֵ�������Ԥ��������δ����ϰ��еı��֡��� MF ��ͬ��ʱ���� KT �е�һ����Ҫ���ء�

��֪��Ϻ�֪ʶ׷�ٵ������������ǵĲ��ص㡣��֪��ϸ���ע��ȡѧϰ�ߵ���֪״̬��Ϊ������ѧϰ�ߵ���֪״̬������ʵ����ѧϰ�ߵ���֪״̬Ԥ��ѧϰ����ȷ�����һ����ϰ�ĸ��ʡ��ӻ���ѧϰ�ĽǶ����֪ʶ��Դģ�;�����׼ȷ��Ԥ��ѧϰ����ȷ�ش���һ��ĸ��ʡ�����̫����ѧϰ�ߵ���֪״̬��ֻҪ������׼ȷ��Ԥ��ѧϰ����ȷ�ش���һ����ϰ��ĸ��ʼ��ɣ���֪ʶ׷�ٸ�����Ԥ��ѧϰ�߻����һ����ϰ��ĸ�����ϰ����Ȩ����

���⣬���е���֪���ģ�ͺ��ٳ������ϰ����֪ʶ����֮���������ϵ����ѧϰ�ߵ�֪ʶ״̬����ֱ�ۡ��ɽ��͵���ϡ���ˣ����о������һ�ֳ�ֽ����ϰ��֪ʶ����֮�����Ժ����Թ�ϵ�Ķ�����ϵ��֪���ģ��

    Matrix factorization (MF) aims to predict learners�� performance in one part of the exercises by the learners�� performance in another part of the exercises. Knowledge tracking (KT) is a task for tracking learners�� performance on exercises in various stages in the past to predict their performance in future exercise activities. Unlike the MF, time is an important factor in KT.

    The difference between cognitive diagnosis and knowledge tracing is their focus. Cognitive diagnosis is more concerned with obtaining the cognitive state of the learners. To evaluate the cognitive state of learners, the probability of learners getting the next exercise right was predicted based on the cognitive state of learners in the experiments. The knowledge tracing model was designed from the perspective of machine learning to predict the probability of learners�� correct answers to the next exercise question as accurately as possible. It is not very concerned about the cognitive state of learners as long as the probability of learners�� correct answers to the next exercise question was predicted as accurately as possible, whereas knowledge tracing is more concerned with predicting the probability that a learner will get the next practice exercise right.

    In addition, existing cognitive diagnosis models rarely make full use of the implicit relationship between exercises and knowledge concepts to make intuitive and interpretable diagnoses of learners�� knowledge states. Therefore, this study proposes a quantitative relationship cognitive diagnosis model that fully combines the explicit and implicit relationships between exercises and knowledge concepts.

��ȻNeuralCDM�ͻ����������֪ʶ׷��ģ�Ͷ������������������н���������������֮�仹�Ǵ���һЩ����

NeuralCDM�봫ͳ��֪ʶ׷�ٷ�������������������������ѧ����֪ʶˮƽ����������ѧ������֪������������ԣ�NeuralCDM��ѧ������֪������Ϊһ���������أ���ʹ��������������ѧ������֪���ģ�͡�����ģ�Ϳ��Զ�ѧ������֪�������н�ģ��Ԥ�⣬���ҿ����ڿ���ѧ����֪�����Ļ����ϸ�׼ȷ�ع���ѧ����֪ʶˮƽ��

���֮�£������������֪ʶ׷��ģ��ͨ���������ڶ�ѧ����֪ʶ����������н�ģ��Ԥ�⡣��Щģ��ͨ��ʹ������������ʾѧ����֪ʶ״̬���Ա���õع���ѧ����֪ʶˮƽ��������ѧ������ʷ����Ԥ��ѧ����δ�����֡�

��ˣ�NeuralCDM������������֪ʶ׷��ģ��֮����������ڣ�NeuralCDM����������ѧ����֪ʶˮƽ����������ѧ������֪������ͨ��������֪�����ĸ����ǿ��ģ�͵ı�������ͷ���������

## ���ʵ��
�����ڼ������磬��ĳ��������ʱ����t������ͬһ���˵�ѧϰ��¼�����������������֪ʶ�ṹ�����ڼ�������Ҫ�Ǻ��������ǹ̶�ֵ