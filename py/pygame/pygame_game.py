import pygame
import sys
from ship import Ship
from settings import Settings
import game_functions as gf

def run_game ():
    pygame.init()
    ai_settings = Settings()
    
    pygame.display.set_caption("这是一个game")
    screen = pygame.display.set_mode(
    (ai_settings.screen_width, ai_settings.screen_height))
    ship = Ship(ai_settings,screen)
    while True :
        gf.cheak_events(ship)
        ship.update()
        gf.update_screen(ai_settings, screen, ship)
run_game()

