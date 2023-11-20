#include<stdio.h>
#include<math.h>

#include "SubFunction.h"

using namespace std;

int SkillDam(Member& member, Skill skill);

void Damcounter(Member& member, Skill* process,const int steps, int* Damage)
{
	int currentDamage = member.ATK;

    for (int i = 0; i<steps; ++i) 
	{
        // Apply buff changes from the skill
        //printf("%d\n",i);
        process[i].applyBuff(member);

        // Calculate damage and store in Damage array
        Damage[i] = SkillDam(member,process[i]);
    }
}

//In this vertion i only use skill.multiplier,but more parameter may be used in following vertions.~(*.^)'~
//So I do give the function whole object
int SkillDam(Member& member, Skill skill)
{
	
	double sum,a[8]={0},Rate,Rate2,Gra,Gra2,BRA,c,x,Double;
	int i=0;
	
	//Rate=66.666666;//18�������������ݣ�33��67��βҪ666666, played in percentile units,XX.XX here means XX.XX%
	//Gra=19;//���ܵȼ�
	//Gra2=Gra+16;//basic muliplier for level 1?
	Rate2=round(skill.multiplier);//�ض��ȼ�����, or mutiplier played in game's skill interface
	Double=1;//���ʷ�������
	BRA=2.5;//�����˺��ӳɳ���
	c=floor(Rate2*BRA*Double);//�򱶱��ʣ�����
	//a[0]=member.ATK; //��幥����, now won't use a[0], assign the ATK value to sum directly
	a[1]=member.buff[0];//�������ٷֱȼӳ�
	x=member.buff[1];//��������ֵ�ӳ�
	a[2]=c/10000;//���ձ��ʣ�����
	a[3]=member.buff[2];//�����˺��ӳɳ���
	a[4]=member.buff[3];//���Կ��Գ��� ������0.7605
	a[5]=member.buff[4];//�����˺��ӳɳ���
	a[6]=member.buff[5];//�����˺�������� ������0.9605
	a[7]=member.buff[6];//�������˳�����������ȼ����
	
	sum=member.ATK; //��幥����
	for(i=1;i<7;i++)//apply a[1] to a[6]
	{
		sum=floor(sum*a[i]);
		if(i==1)
		{
			sum=sum+x;
		}
		//printf("a%lf\n",a[i]);
	}
	sum=ceil(sum*a[7]);
	//printf("sum:%lf\n",sum);
	
	return (int)sum;
}

