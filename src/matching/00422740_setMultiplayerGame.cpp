void RGE_Base_Game::setMultiplayerGame(int v)
{
    this->multiplayerGame_ = (unsigned char)v;
    this->singlePlayerGame_ = (unsigned char)(v == 0);
}
