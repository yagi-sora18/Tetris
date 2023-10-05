/************************************
*�v���O���~���O���K�i�e�g���X�ҁj
*************************************/
#include"DxLib.h"
#include"FreamControl.h"
#include"SceneManager.h"
#include"InputControl.h"

/************************************
*�}�N����`
*************************************/
#define SCREEN_HEIGHT(720)
#define SCREEN_WIDTH (1280)
#define SCREEN_COLORBIT    (32)
#define FONT_SIZE (20)

/************************************
*�^��`
*************************************/



/************************************
*�O���[�o���ϐ���`
*************************************/



/************************************
*�v���g�^�C�v�錾
*************************************/



/************************************
*�v���O�����̊J�n
*************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�^�C�g����ύX
	SetMainWindowText("�e�g���X");

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�̌���
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[����
		return -1;

	}

	//�t���[������@�\����������
	FreamControl_Initialize();

	//�V�[���Ǘ��@�\����������
	SceneManager_Initialize(E_TITLE);

	//���͐���@�\����������
	InputControl_Initialize();

	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�����T�C�Y��ݒ�
	SetFontSize(FONT_SIZE);

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && GetExitButton() != TRUE && ErrorCheck() == D_NORMALITY)
	{
		//�t���[������@�\�X�V����
		FreamControl_Update();

		//��ʏ�����
		ClearDrawScreen();

		//���͐���@�\�X�V����
		InputControl_Update();

		//�V�[���Ǘ��@�\�X�V����
		SceneManager_Update();

		//�V�[���Ǘ��@�\�`�揈��
		SceneManager_Draw();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}


	//���͑ҋ@
	WaitKey();


	//Dx���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}
