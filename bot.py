import os
from TikTokLive import TikTokLiveClient
from TikTokLive.events import CommentEvent

client = TikTokLiveClient(unique_id="@miotools6")
client.web.set_session(os.environ["TIKTOK_SESSION"])

@client.on(CommentEvent)
async def on_comment(event: CommentEvent):
    if event.comment.strip().lower() == "/t":
            await client.send_room_chat("v1")

            client.run()