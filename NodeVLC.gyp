{
  'targets': [
    {
      'target_name': 'node-vlc',
      'sources': [ 'NodeVLC.cc', 'VLCMedia.cc' ],
      'link_settings': {
      	'libraries': [
          '-lvlc'
        ]
      }
    }
  ]
}