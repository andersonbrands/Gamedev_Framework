/***************************************************************************************
*	Title: D3dKeyboard.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "D3dKeyboard.h"
#include "../../../Framework/Platform/Platform.h"

D3dKeyboard::D3dKeyboard() {
    assert(Platform::getInstancePtr());
    WindowsPlatform* pWin(static_cast<WindowsPlatform*>(Platform::getInstancePtr()));
    assert(pWin);

    // Create the DirectInput object.
    if(FAILED(DirectInput8Create( pWin->getHInst(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&mpDI_, nullptr)))
        MessageBox(NULL, "DInput8Create failed", "Error", MB_OK);

    // Retrieve a pointer to an IDirectInputDevice8 interface.
    if(FAILED(mpDI_->CreateDevice(GUID_SysKeyboard, &pDIKeyboardDevice_, nullptr)))
        MessageBox(NULL, "DInput CreateDevice failed", "Error", MB_OK);

    // Set the data format using the predefined keyboard data format.
    if(FAILED(pDIKeyboardDevice_->SetDataFormat(&c_dfDIKeyboard)))
        MessageBox(NULL, "Failed to set data format for keyboard", "Error", MB_OK);

    // Set the cooperative level
    if(FAILED(pDIKeyboardDevice_->SetCooperativeLevel(pWin->getHWnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
        MessageBox(NULL, "Failed to set cooperative level of keyboard", "Error", MB_OK);

    pDIKeyboardDevice_->Acquire();

    ZeroMemory(&buffer_, BUFFER_SIZE);
    ZeroMemory(&lastBuffer_, BUFFER_SIZE);
}

D3dKeyboard::~D3dKeyboard() {
    if (mpDI_) {
        if (pDIKeyboardDevice_) {
            // Always unacquire device before calling Release().
            pDIKeyboardDevice_ -> Unacquire();
            pDIKeyboardDevice_ -> Release();
            pDIKeyboardDevice_ = nullptr;
        }
        mpDI_ -> Release();
        mpDI_ = nullptr;
    }
}

void D3dKeyboard::update() {
    HRESULT hr;

    //remember what was down, so we know when something is pressed and released
    memcpy(lastBuffer_, buffer_, BUFFER_SIZE);

    // Clear the buffer for keyboard data - just in case.
    ZeroMemory(&buffer_, BUFFER_SIZE);

    hr = pDIKeyboardDevice_->GetDeviceState(sizeof(buffer_),(LPVOID)&buffer_);
    if FAILED(hr) {
        // If this failed, the device has probably been lost.
        // Check for (hr == DIERR_INPUTLOST) and attempt to reacquire it here.
        hr = pDIKeyboardDevice_->Acquire();
        while (hr == DIERR_INPUTLOST)
            hr = pDIKeyboardDevice_->Acquire();

        hr = pDIKeyboardDevice_->GetDeviceState(sizeof(buffer_),(LPVOID)&buffer_);
    }
}

bool D3dKeyboard::isKeyDown(unsigned char charCode) {
    return (buffer_[charCode] & 0x80) ? true : false;
}

bool D3dKeyboard::onKeyDown(unsigned char dikCode) {
    return isKeyDown(dikCode) && !(lastBuffer_[dikCode]&0x80);
}

bool D3dKeyboard::onKeyUp(unsigned char dikCode) {
    return !isKeyDown(dikCode) && (lastBuffer_[dikCode]&0x80);
}