# Ƕ��
torch.nn. Ƕ�루num_embeddings�� embedding_dim�� padding_idx = None�� max_norm = None�� norm_type = 2.0�� scale_grad_by_freq = False�� sparse = False�� _weight = None�� _freeze = False�� device = None�� dtype = None��

һ���򵥵Ĳ��ұ����ڴ洢�̶��ֵ�ʹ�С��Ƕ�롣

��ģ��ͨ�����ڴ洢��Ƕ�벢ʹ�������������ǡ���ģ���������һ�������б��������Ӧ�Ĵ�Ƕ�롣

������

    num_embeddings ( int ) �C Ƕ���ֵ�Ĵ�С

    embedding_dim ( int ) �C ÿ��Ƕ�������Ĵ�С

    padding_idx ( int , optional ) �C ���ָ��������Ŀpadding_idx��Ӱ���ݶȣ���ˣ�Ƕ������padding_idx��ѵ���ڼ䲻����£���������Ϊ�̶��ġ�pad���������¹���� Embedding��Ƕ������padding_idx��Ĭ��Ϊȫ�㣬�����Ը���Ϊ��һ��ֵ���������������

    max_norm ( float , optional ) �C ���������ÿ���������ڵ�Ƕ������max_norm �����¹�һ��Ϊ�з���max_norm��

    norm_type ( float , optional ) �C ҪΪѡ������ p ������ p max_norm��Ĭ��2��

    scale_grad_by_freq ( bool , optional ) �C ����������⽫��С�����е���Ƶ�ʵĵ����������ݶȡ�Ĭ��False��

    sparse ( bool , optional ) �C ���True���ݶ� wrtweight������һ��ϡ���������й�ϡ���ݶȵĸ�����ϸ��Ϣ����μ�ע�͡�

������

    weight ( Tensor ) �C ��״ģ��Ŀ�ѧϰȨ�� (num_embeddings, embedding_dim) ��? ( 0 ,1 )

��״��

    ���룺( * )������Ҫ��ȡ��������������״�� IntTensor �� LongTensor

    �����
    ��* ,H��������*��������״��H=embedding_dim

# LINEAR
    torch.nn.Linear(in_features, out_features, bias=True, device=None, dtype=None)

�Դ�������Ӧ�����Ա任��$y=xA^T+b$

![](20230328155738.png)

## ����
    in_features ( int ) �C ÿ�����������Ĵ�С

    out_features ( int ) �C ÿ����������Ĵ�С

    bias ( bool ) �C �������ΪFalse���ò㽫����ѧϰ����ƫ�Ĭ�ϣ�True

## ��״

$
    ���룺��*��H_{in}��*��ʾ����������ά�ȣ�����none��H{in}=infeatures
    �����*��H_{out}���������һ��ά��֮�������ά�ȶ����������״��ͬ��H_{out}=outfeatures
$

## ����

![](20230327104730.png)

# Dropout
    torch.nn.Dropout(p=0.5, inplace=False)
p��ѵ���ڼ䣬ʹ�����Բ�Ŭ���ֲ��������Ը��ʽ�����������ĳЩԪ��������㡣ÿ��ͨ��������ÿ��ת������ʱ�������㡣

��������Improving neural networks by preventing co-adaptation of feature detectors�����������ѱ�֤����һ���������򻯺ͷ�ֹ��Ԫ��ͬ��Ӧ����Ч���� ��

���⣬��������������� $1/(1-P)$ѵ���С�����ζ���������ڼ䣬ģ��ֻ�Ǽ���һ����Ⱥ���

## ����

    p ( float ) �C Ԫ�ع���ĸ��ʡ�Ĭ��ֵ��0.5

    inplace ( bool ) �C �������ΪTrue�����͵�ִ�д˲�����Ĭ�ϣ�False

## ��״

    ���룺( * ). ����������κ���״

    �����( * ). ��������������ͬ����״

