#include <math.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define NUM_OF_TRAINING_LOOPS   1000
#define LR                      -0.1

struct Data
{
	double t[20];
	double u[20];
	double y[20];
};

Data trainingData[5];

double inputs[2];
double weights_IH[2][3];
double h1[3];
double b_H1[3];
double weights_H1H2[3][2];
double h2[2];
double b_H2[2];
double output;
double cost = 0;
double error = 0;
double sumErrorSQ = 0;

double Sigmoid(double x)
{
	//e^x / (e^x+1)
	double result;
	result = exp(x) / (exp(x) + 1);
	return result;
}

void FillArray(Data *d,double u)
{
	for(int i = 0; i < 21;i++)
	{
		d->t[i] = i;
		d->u[i] = u;
		d->y[i] = 0.24 * (d->u[i]-(exp(-d->t[i]/3)));
	}
}

double RandomNumber()
{
	double num = static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(2)));
	num += - 1;
	if(num == 0){num = 1;}
	return num;
}

void InitialRandomWeights_Bias()
{
	for (int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 3; j++)
		{
			weights_IH[i][j] = RandomNumber();
			weights_H1H2[j][i] = RandomNumber();
			b_H1[j] = RandomNumber();
		}
		b_H2[i] = RandomNumber();
	}
}


double OutputDerivative()
{
	double k = h2[0]*h2[0];
	double t = exp((-2*inputs[1]));
	double T = h2[1]*h2[1];
	return k*((t/T)+1);
}

double SigmoidDerivative(double y)
{
	return y* (1 - y);
}


int main()
{
	srand(time(NULL));

	InitialRandomWeights_Bias();
	
	FillArray(&trainingData[0],0);
	FillArray(&trainingData[1],10);
	FillArray(&trainingData[2],50);
	FillArray(&trainingData[3],68);
	FillArray(&trainingData[4],79);


	//Choose random test data
	for(int i = 0; i<NUM_OF_TRAINING_LOOPS;i++)
	{
		int randomDataSet = 0 + rand() % 4;
		int randomIndex = 0 + rand() % 20;
		inputs[0] = trainingData[randomDataSet].u[randomIndex];
		inputs[1] = trainingData[randomDataSet].t[randomIndex];
		//Feeding forward---------------------------------------------------------------------------

		//Hidden layer 1
		//Calculate H1_1
		double temp = (inputs[0] * weights_IH[0][0]) + (inputs[1] * weights_IH[1][0]) + b_H1[0];
		printf("temp H1_0 = %f",temp);
		h1[0] = Sigmoid(temp);
		//Calculate H1_2
		temp = (inputs[0] * weights_IH[0][1]) + (inputs[1] * weights_IH[1][1]) + b_H1[1];
		printf("temp H1_2 = %f",temp);
		h1[1] = Sigmoid(temp);
		//Calculate H1_3
		temp = (inputs[0] * weights_IH[0][2]) + (inputs[1] * weights_IH[1][2]) + b_H1[2];
		printf("temp H1_2 = %f",temp);
		h1[2] = Sigmoid(temp);


		//Hidden layer 2
		//Calculate H2_1
		temp = (h1[0] * weights_H1H2[0][0]) + (h1[1] * weights_H1H2[1][0]) + (h1[2] * weights_H1H2[2][0]) + b_H2[0];
		printf("temp H2_0 = %f",temp);
		h2[0] = Sigmoid(temp);
		//Calculate H2_2
		temp = (h1[0] * weights_H1H2[0][1]) + (h1[1] * weights_H1H2[1][1]) + (h1[2] * weights_H1H2[2][1]) + b_H2[1];
		printf("temp H2_1 = %f",temp);
		h2[1] = Sigmoid(temp);
	
		output = h2[0] * (inputs[0] - (exp(-inputs[1]/h2[1])));
	
		//End of Feeding Forward -------------------------------------------------------------------------------------
		
		//Calculating Each layers Error ------------------------------------------------------------------------------
		error = trainingData[randomDataSet].y[randomIndex] - output;
		cost += error*error;
		if(isnan(cost) > 0)
		{
			printf("NAN occured with Error = %f\n",error);
			printf("NAN occured with Output = %f\n",output);
			printf("NAN occured with h1_0 = %f\n",h1[0]);
			printf("NAN occured with h1_1 = %f\n",h1[1]);
			printf("NAN occured with h1_2 = %f\n",h1[2]);
			printf("\n");
			printf("NAN occured with h2_U = %f\n",h2[0]);
			printf("NAN occured with h2_T = %f\n",h2[1]);
			printf("---------------------------------------------------------------------\n");
		}
		
		double h2_error[2];
		h2_error[0] = (h2[0] * error);
		h2_error[1] = (h2[1] * error);
		
		double h1_error[3];
		h1_error[0] = (h1[0] * h2_error[0]) + (h1[0] * h2_error[1]);
		h1_error[1] = (h1[1] * h2_error[0]) + (h1[1] * h2_error[1]);
		h1_error[2] = (h1[2] * h2_error[0]) + (h1[2] * h2_error[1]);
		
		
		//End of Calculating Each layers Error ------------------------------------------------------------------------------
		
		//Back Propergation -------------------------------------------------------------------------------------------------
		b_H2[0] += LR * error * OutputDerivative();
		b_H2[1] += LR * error * OutputDerivative();
		
		for(int w = 0; w < 3;w++)
		{
			weights_H1H2[w][0] += LR * h2_error[0] * SigmoidDerivative(h2[0]);
			weights_H1H2[w][1] += LR * h2_error[1] * SigmoidDerivative(h2[1]);
		}
		
		b_H1[0] += LR * h1_error[0] * SigmoidDerivative(h1[0]);;
		b_H1[1] += LR * h1_error[1] * SigmoidDerivative(h1[1]);;
		b_H1[1] += LR * h1_error[2] * SigmoidDerivative(h1[2]);;
		
		for(int w = 0; w < 3;w++)
		{
			weights_IH[0][w] += LR * h1_error[0] * SigmoidDerivative(h1[0]);
			weights_IH[1][w] += LR * h1_error[1] * SigmoidDerivative(h1[1]);
			weights_IH[2][w] += LR * h1_error[2] * SigmoidDerivative(h1[2]);
		}
		//End of back propergation ------------------------------------------------------------------------------------------
		double errorSQ = error * error;
		sumErrorSQ +=errorSQ;
		if(i%10 == 0){
			sumErrorSQ /=100;
		   // printf("Error = %f\n",sumErrorSQ);
			sumErrorSQ = 0;
		}
		
	}
	printf("Cost = %f\n",cost);
	//printf("H1_1 = %f, H1_2 = %f, H1_3 = %f\n",h1[0],h1[1],h1[2]);


}