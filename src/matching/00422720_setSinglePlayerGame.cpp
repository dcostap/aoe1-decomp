void RGE_Base_Game::setSinglePlayerGame(int v)
{
    this->singlePlayerGame_ = (unsigned char)v;
    this->multiplayerGame_ = (unsigned char)(v == 0);
}
