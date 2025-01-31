
#include "DxLib.h"
#include "InputManager.h"

// ================================================================================
// グローバル関数
// ================================================================================
StKeyState		m_state[MY_INPUT_MAX];


// ================================================================================
// 入力処理初期化 (ゲーム起動時に一度だけ呼び出す)
// ================================================================================
void InputInit()
{
	for( int i=0; i < MY_INPUT_MAX; i++ )
	{
		m_state[i].old	= false;
		m_state[i].push	= false;
		m_state[i].on	= false;
		m_state[i].pull	= false;
	}
}

// ================================================================================
// 入力更新処理
// ================================================================================
void InputUpdate()
{
	for( int i=0; i < MY_INPUT_MAX; i++ )
	{
		const bool now	= (CheckHitKey(KEY_ASSIGN[i]) == 1);

		m_state[i].on   = now;
		m_state[i].push = now & !m_state[i].old;
		m_state[i].pull = !now & m_state[i].old;

		m_state[i].old = now;
	}
}

// ================================================================================
// キーが押されたか
// ================================================================================
bool IsPushKey( int key )
{
	if( MY_INPUT_START <= key && key < MY_INPUT_END )
	{
		return m_state[key].push;
	}
	return false;
}

// ================================================================================
// キーが押下されているか
// ================================================================================
bool IsOnKey( int key )
{
	if( MY_INPUT_START <= key && key < MY_INPUT_END )
	{
		return m_state[key].on;
	}
	return false;
}

// ================================================================================
// キーが離されたか
// ================================================================================
bool IsPullKey( int key )
{
	if( MY_INPUT_START <= key && key < MY_INPUT_END )
	{
		return m_state[key].pull;
	}
	return false;
}
